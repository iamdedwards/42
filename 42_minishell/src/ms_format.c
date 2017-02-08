/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:33 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:07:54 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ms_zprompt_print(t_ms_ctx *ctx, char *pwd)
{
	if (!ctx->signals.interrupt)
	{
		ft_printf("\e[38;5;%dm%C \e[3m\e[39m%s \e[1m\e[38;5;%dm%C%C",
			ctx->prompt_colour * 6,
			L'≣',
			pwd,
			ctx->prompt_colour * 6,
			L'ᜰ',
			L'⊳');
		ft_printf("\e[38;5;%dm>\e[0m ", ctx->prompt_colour * 9);
	}
	else
	{
		ft_printf("\e[31m%C \e[3m\e[39m%s \e[1m\e[31m%C%C",
			L'≣',
			pwd,
			L'ᜰ',
			L'⊳');
		ft_printf("\e[31m>\e[0m ");
		ctx->signals.interrupt = 0;
	}
}

void			ms_zprompt(t_ms_ctx *ctx)
{
	char			*pwd;
	t_list			*pwd_split;
	char			curr_dir[MS_BUFF_SIZE];

	pwd_split = ms_env_get_list(ctx->env, "PWD_SPLIT");
	if (pwd_split)
	{
		pwd = l_last(pwd_split)->content;
	}
	else
	{
		getcwd(curr_dir, MS_BUFF_SIZE);
		ms_env_xset_val(ctx, "PWD", curr_dir);
		pwd_split = ms_env_get_list(ctx->env, "PWD_SPLIT");
		pwd = l_last(pwd_split)->content;
	}
	if (!*pwd)
		pwd = "/";
	ms_zprompt_print(ctx, pwd);
}
