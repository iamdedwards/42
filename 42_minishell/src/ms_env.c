/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:30 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 12:00:52 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_print_env(t_ms_ctx *ctx)
{
	t_dictionary	env_dict;
	t_list			*values_list;

	env_dict = ctx->env;
	while (env_dict.values)
	{
		if (!s_equals(env_dict.keys->content, "PWD_SPLIT"))
		{
			ft_printf("%s=",
			(env_dict.keys->content));
			values_list = env_dict.values->content;
			while (values_list)
			{
				ps(values_list->content);
				if (values_list->next)
					ps(":");
				values_list = values_list->next;
			}
			ps("\n");
		}
		env_dict.keys = env_dict.keys->next;
		env_dict.values = env_dict.values->next;
	}
}

char				**sv_move_del(char ***sv_ref, int n)
{
	int				len;
	int				i;
	char			**sv;

	i = 0;
	sv = *sv_ref;
	len = sv_len(sv);
	while (i < n)
		s_del(&sv[i++]);
	i = 0;
	while (sv[i + n])
	{
		sv[i] = sv[i + n];
		i++;
	}
	sv[i] = 0;
	return (sv);
}

void				ms_envi(t_ms_ctx *ctx)
{
	char			**hold_env;

	if (ctx->args[2])
	{
		sv_move_del(&ctx->args, 2);
		if (!ctx->args[0])
			return ;
		hold_env = ctx->env_as_sv;
		ctx->env_as_sv = NULL;
		ms_find_exec(ctx);
		ctx->env_as_sv = hold_env;
	}
}

int					ms_env(t_ms_ctx *ctx)
{
	if (ctx->args[1])
	{
		if (s_equals(ctx->args[1], "-i"))
		{
			ms_envi(ctx);
		}
		return (0);
	}
	ms_print_env(ctx);
	return (1);
}

int					ms_unsetenv(t_ms_ctx *ctx)
{
	if (ctx->args[1])
	{
		ms_env_unset_val(ctx, ctx->args[1]);
		return (1);
	}
	return (0);
}
