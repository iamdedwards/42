/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_val_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:31 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 12:11:30 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ms_env_xset(t_list **values, t_list *value)
{
	t_list			*values_split;

	values_split = (*values)->content;
	l_destroy(&values_split, x_del);
	if (value)
		(*values)->content = value;
}

static void			ms_env_cat(t_list **values, t_list *value)
{
	t_list			*values_split;

	values_split = (*values)->content;
	l_last(values_split)->next = value;
}

static void			ms_pwd_trigger(t_ms_ctx *ctx, char *key, char *val)
{
	t_list			*pwd_split_key;
	t_list			*pwd_split_value;

	if (s_equals(key, "PWD"))
	{
		ms_env_key_vals(&ctx->env, "PWD_SPLIT",
				&pwd_split_key, &pwd_split_value);
		if (!pwd_split_key)
		{
			l_push(&ctx->env.keys, l_new_s(s_dup("PWD_SPLIT")));
			if (!s_equals(val, "/"))
				l_push(&ctx->env.values, l_new(l_dissect(val, "/"), *key));
			else
				l_push(&ctx->env.values, l_new(l_new_s(s_dup("")), *key));
		}
		else
		{
			if (!s_equals(val, "/"))
				ms_env_xset(&pwd_split_value, l_dissect(val, "/"));
			else
				ms_env_xset(&pwd_split_value, l_new_s(s_dup("")));
		}
	}
}

static void			ms_env_unset(t_ms_ctx *ctx, t_list **keys, t_list **values)
{
	t_list			*xenv_keys;
	t_list			*xenv_values;

	xenv_keys = l_grab_ref(&ctx->env.keys, keys);
	xenv_values = l_grab_ref(&ctx->env.values, values);
	x_del((void **)&xenv_keys);
	x_del((void **)&xenv_values);
}

int					ms_env_val_set_proto(t_ms_ctx *ctx,
					char *key, char *val, int mode)
{
	t_list				*env_keys;
	t_list				*env_values;
	t_ms_env_val_setter	setter;
	t_list				*values;

	setter = (mode == 1) ? ms_env_cat : ms_env_xset;
	values = (mode == -1) ? 0 : l_dissect(val, ":");
	if (!ms_env_key_vals(&ctx->env, key, &env_keys, &env_values) && mode != -1)
	{
		l_push(&ctx->env.keys, l_new_s(key));
		l_push(&ctx->env.values, l_new(values, *key));
	}
	else if (env_keys)
	{
		setter(&env_values, values);
		if (mode == -1)
			ms_env_unset(ctx, &env_keys, &env_values);
	}
	if (mode != -1)
		ms_pwd_trigger(ctx, key, val);
	sv_del(&ctx->env_as_sv);
	ctx->env_as_sv = ms_env_sv(ctx->env);
	if (s_equals(key, "PATH"))
		ms_set_binary_files(ctx);
	return (env_keys != 0);
}
