/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_destroy_ctx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:30 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 12:07:05 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_env_node_del(void **x)
{
	t_list			**y;

	y = (t_list **)x;
	l_destroy(y, x_del);
}

void				ms_destroy_ctx(t_ms_ctx *ctx)
{
	l_destroy(&ctx->key_map.keys, x_del);
	l_destroy(&ctx->key_map.values, 0);
	l_destroy(&ctx->xkey_map.keys, x_del);
	l_destroy(&ctx->xkey_map.values, 0);
	l_destroy(&ctx->cmds.keys, x_del);
	l_destroy(&ctx->cmds.values, 0);
	l_destroy(&ctx->history, x_del);
	l_destroy(&ctx->curr_files, x_del);
	l_destroy(&ctx->binary_files, x_del);
	l_destroy(&ctx->shell_var.keys, x_del);
	l_destroy(&ctx->shell_var.values, x_del);
	l_destroy(&ctx->env.keys, x_del);
	l_destroy(&ctx->env.values, ms_env_node_del);
	sv_del(&ctx->env_as_sv);
}

void				ms_destroy_input(t_ms_input *input)
{
	ms_remove_select_values(input);
	ms_destroy_select_values(input);
	l_destroy(&input->str_div, x_del);
	s_del(&input->match);
}
