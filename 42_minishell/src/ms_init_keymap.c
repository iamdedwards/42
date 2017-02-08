/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_keymap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:36 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 14:34:51 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*ms_xkey(char key)
{
	char			*str_key;

	if (key != 0)
		str_key = s_dup((char[]){27, 91, key, 0});
	else
		str_key = s_dup((char[]){27, 0});
	return (str_key);
}

char			*ms_ignore_key(char key)
{
	return (s_dup((char[]){27, key, 0}));
}

char			*ms_key(char key)
{
	return (s_dup((char[]){key, 0}));
}

void			ms_null(t_ms_input *input)
{
	input->xxkey = 1;
}

void			ms_init_keymaps(t_ms_ctx *ctx)
{
	ctx->xkey_map = dict_init((void **[]){
		(void *[]){ms_xkey(0), ms_escape},
		(void *[]){ms_xkey('A'), ms_up},
		(void *[]){ms_xkey('B'), ms_down},
		(void *[]){ms_xkey('C'), ms_right},
		(void *[]){ms_xkey('D'), ms_left},
		(void *[]){ms_xkey('H'), ms_home},
		(void *[]){ms_xkey('F'), ms_end},
		(void *[]){ms_xkey(51), ms_null},
		(void *[]){ms_xkey(53), ms_null},
		(void *[]){ms_xkey(54), ms_null},
		NULL});
	ctx->key_map = dict_init((void **[]){
		(void *[]){ms_key(3), ms_sig_interupt},
		(void *[]){ms_key(4), ms_sig_eof},
		(void *[]){ms_key('\n'), ms_reduce_line},
		(void *[]){ms_key(127), ms_erase},
		(void *[]){ms_key('\t'), ms_tab},
		NULL});
}
