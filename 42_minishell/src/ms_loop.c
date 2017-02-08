/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:37 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 13:35:36 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_cd_redirect(t_ms_ctx *ctx)
{
	char			tmp[1024];
	int				file_type;

	if ((!ctx->args[0])
	|| (ctx->args[1]))
		return ;
	file_type = ms_is_file(ctx->args[0]);
	if (file_type != MS_DIR)
		return ;
	if (dict_get_val(ctx->cmds, ctx->args[0]))
		return ;
	if (ms_binary_exists(ctx, ctx->args[0]))
		return ;
	s_clear(tmp, 1024);
	s_cpy(s_tail(tmp, 0), "cd ");
	s_cpy(s_tail(tmp, 0), ctx->args[0]);
	sv_del(&ctx->args);
	ctx->args = s_dissect(tmp, " ");
}

void				ms_find_exec(t_ms_ctx *ctx)
{
	t_ms_cmd			cmd;

	if (!ctx->args)
	{
		return ;
	}
	ms_cd_redirect(ctx);
	cmd = dict_get_val(ctx->cmds, ctx->args[0]);
	if (!cmd)
	{
		if (ms_execute(ctx) == -1)
		{
			TX_IF("FORK ERROR!");
		}
	}
	else
	{
		cmd(ctx);
	}
}

void				ms_ready_find_exec(t_ms_ctx *ctx, char **ln)
{
	if ((*ln) && (**ln))
	{
		ctx->args = ms_args(ctx, *ln);
		ms_find_exec(ctx);
		sv_del(&ctx->args);
	}
}

void				ms_loop_split_cmds(t_ms_ctx *ctx, char **ln)
{
	t_list				*ln_lst;
	t_list				*run;

	if (!s_haschar(*ln, ';'))
	{
		ms_s_clean(ln);
		if (!ms_script(ctx, *ln))
			ms_ready_find_exec(ctx, ln);
	}
	else
	{
		ln_lst = l_dissect(*ln, ";");
		run = ln_lst;
		while (run)
		{
			ms_s_clean((char **)&run->content);
			if (!ms_script(ctx, run->content))
				ms_ready_find_exec(ctx, (char **)&run->content);
			run = run->next;
		}
		l_destroy(&ln_lst, x_del);
	}
}

void				ms_loop(t_ms_ctx *ctx)
{
	char			*ln;

	while (!ctx->signals.eof)
	{
		ms_zprompt(ctx);
		ln = ms_get_line(ctx);
		if (ms_env_get_str(ctx->env, "WOW"))
			ctx->prompt_colour += 1;
		if (ln && *ln)
		{
			ms_loop_split_cmds(ctx, &ln);
		}
		s_del(&ln);
	}
}
