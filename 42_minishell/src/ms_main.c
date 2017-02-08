/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:37 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 18:07:51 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ms_ctx		*ms_saved_ctx(t_ms_ctx *ctx)
{
	static t_ms_ctx	*saved_ctx = 0;

	if (ctx)
	{
		saved_ctx = ctx;
	}
	return (saved_ctx);
}

t_ms_ctx			*ms_get_ctx(void)
{
	return (ms_saved_ctx(0));
}

void				ms_set_ctx(t_ms_ctx *ctx, char **env)
{
	ctx->prompt_colour = 7;
	ctx->shell_var.keys = 0;
	ctx->shell_var.values = 0;
	ctx->curr_files = 0;
	ctx->binary_files = 0;
	ms_init_keymaps(ctx);
	ms_init_cmds(ctx);
	ms_init_env(ctx, env);
	ctx->env_as_sv = ms_env_sv(ctx->env);
	ms_set_binary_files(ctx);
	ms_set_curr_files(ctx);
	ctx->history = 0;
	ctx->signals.interrupt = 0;
	ctx->signals.eof = 0;
	ms_saved_ctx(ctx);
}

int					main(int ac, char **av, char **env)
{
	t_ms_ctx		ctx;
	char			*term;

	signal(SIGINT, ms_set_sig_interrupt);
	(void)ac;
	(void)av;
	ms_set_ctx(&ctx, env);
	term = ms_env_get_str(ctx.env, "TERM");
	if (!term)
	{
		term = "what?";
	}
	tgetent(0, term);
	ms_loop(&ctx);
	ps("\n");
}
