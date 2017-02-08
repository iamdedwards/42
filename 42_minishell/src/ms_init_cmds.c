/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:36 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 09:31:55 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_init_cmds(t_ms_ctx *ctx)
{
	ctx->cmds = dict_init((void **[]){
	(void *[]){s_dup("cd"), ms_cd},
	(void *[]){s_dup("exit"), ms_exit},
	(void *[]){s_dup("env"), ms_env},
	(void *[]){s_dup("setenv"), ms_setenv},
	(void *[]){s_dup("export"), ms_export},
	(void *[]){s_dup("unsetenv"), ms_unsetenv},
	(void *[]){s_dup("echo"), ms_echo},
	NULL});
}
