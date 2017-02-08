/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:38 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 14:27:39 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					call_key_func(t_ms_input *input, char *buff)
{
	t_ms_input_func	key_func;

	key_func = dict_get_val(input->ctx->key_map, buff);
	if (!key_func)
		key_func = dict_get_val(input->ctx->xkey_map, buff);
	if (key_func)
	{
		if (input->select_mode)
		{
			if (key_func != ms_tab)
			{
				ms_remove_select_values(input);
				ms_destroy_select_values(input);
			}
			if (key_func != ms_reduce_line)
				key_func(input);
		}
		else
			key_func(input);
		return (1);
	}
	else
		ms_remove_select_values(input);
	return (0);
}

void				ms_reader(t_ms_input *input)
{
	int				ret;
	char			buff[4];

	s_clear(buff, 5);
	ret = read(0, buff, 3);
	if (!ret)
	{
		TX_IF("read error");
	}
	if (!call_key_func(input, buff))
	{
		if (!(input->xxkey && *buff == '~'))
		{
			pc(*buff);
			ms_remove_select_values(input);
			ms_destroy_select_values(input);
			ms_reader_write(input, buff);
		}
		else
			input->xxkey = 0;
	}
}
