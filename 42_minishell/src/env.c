/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:29 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 12:09:10 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list				*ms_env_get_list(t_dictionary env_dict, char *key)
{
	int				i;

	i = 0;
	while (env_dict.keys)
	{
		if (s_equals(env_dict.keys->content, key))
		{
			return (l_goto(env_dict.values, i)->content);
		}
		env_dict.keys = env_dict.keys->next;
		i++;
	}
	return (0);
}

char				*ms_env_get_str(t_dictionary env_dict, char *key)
{
	t_list			*x;

	x = ms_env_get_list(env_dict, key);
	if (x)
		return (x->content);
	return (0);
}

void				ms_init_env(t_ms_ctx *ctx, char **env)
{
	int				i;
	char			*key;
	char			*value;
	int				split;

	ctx->env = (t_dictionary){0, 0};
	i = 0;
	while (env[i])
	{
		split = s_nto_c(env[i], '=');
		value = &env[i][split + 1];
		env[i][split] = 0;
		key = env[i];
		if (s_equals(key, "PWD"))
		{
			l_push(&ctx->env.keys, l_new_s(s_dup("PWD_SPLIT")));
			l_push(&ctx->env.values, l_new(l_dissect(value, "/"), *value));
		}
		l_push(&ctx->env.keys, l_new_s(s_dup(key)));
		l_push(&ctx->env.values, l_new(l_dissect(value, ":"), *value));
		i++;
	}
}
