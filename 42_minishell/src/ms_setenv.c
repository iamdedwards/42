/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:39 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 11:52:51 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ms_export(t_ms_ctx *ctx)
{
	size_t			split;
	char			*key;
	char			*value;

	if (!s_haschar(ctx->args[1], '='))
		return (0);
	split = s_nto_c(ctx->args[1], '=');
	if (split == s_len(ctx->args[1]) - 1)
		return (0);
	value = &ctx->args[1][split + 1];
	ctx->args[1][split] = 0;
	key = ctx->args[1];
	if (*s_tail(key, 1) == '+')
	{
		*s_tail(key, 1) = 0;
		ms_env_cat_val(ctx, key, value);
	}
	else
		ms_env_xset_val(ctx, key, value);
	return (1);
}

int					ms_setenv(t_ms_ctx *ctx)
{
	if (!ctx->args[1])
		return (ms_env(ctx));
	if (!s_haschar(ctx->args[1], '='))
	{
		if (ctx->args[2])
		{
			ms_env_xset_val(ctx, (ctx->args[1]), ctx->args[2]);
			return (1);
		}
		else
		{
			return (0);
		}
	}
	else
		return (ms_export(ctx));
	return (1);
}
