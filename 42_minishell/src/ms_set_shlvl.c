/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:21:34 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 12:24:31 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					sv_s_where(char **sv, char *s,
					int (*s_func)(char *s1, char *s2))
{
	int				i;

	i = 0;
	while (sv[i])
	{
		if (s_func(sv[i], s))
			return (1);
		i++;
	}
	return (0);
}

int					ms_is_minishell_exec(t_ms_ctx *ctx)
{
	if (!sv_s_where(ctx->args, "./minishell", s_equals))
	{
		if (!sv_s_where(ctx->args, "minishell", s_equals))
			return (0);
	}
	return (1);
}

void				ms_set_shlvl(t_ms_ctx *ctx, int inc_dec)
{
	int				shell_lvl;
	char			*shell_lvl_str;

	if (!ctx->env_as_sv)
		return ;
	shell_lvl_str = ms_env_get_str(ctx->env, "SHLVL");
	if (!shell_lvl_str)
	{
		return ;
	}
	shell_lvl = s_to_i(shell_lvl_str);
	ms_env_xset_val(ctx, "SHLVL", i_to_s(shell_lvl + inc_dec));
}
