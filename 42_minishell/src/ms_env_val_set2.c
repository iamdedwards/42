/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_val_set2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:31 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 11:47:52 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_env_cat_val(t_ms_ctx *ctx, char *key, void *val)
{
	char			*alloc_key;

	alloc_key = s_dup(key);
	if (ms_env_val_set_proto(ctx, alloc_key, val, 1))
		s_del(&alloc_key);
}

void				ms_env_xset_val(t_ms_ctx *ctx, char *key, void *val)
{
	char			*alloc_key;

	alloc_key = s_dup(key);
	if (ms_env_val_set_proto(ctx, alloc_key, val, 0))
		s_del(&alloc_key);
}

void				ms_env_unset_val(t_ms_ctx *ctx, char *key)
{
	(ms_env_val_set_proto(ctx, key, 0, -1));
}
