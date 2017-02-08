/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_reader_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:38 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:47 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					check_insertion(t_ms_input *input)
{
	char			*r_str;
	char			*dup_r_str;

	if (input->insert_index)
	{
		r_str = ms_current_buff_node(input)->content;
		dup_r_str = s_dup(s_tail(r_str, input->insert_index));
		*s_tail(ms_current_buff_node(input)->content, input->insert_index) = 0;
		ms_alloc_buff(input, 0);
		ms_alloc_buff(input, dup_r_str);
		input->current_div++;
		input->insert_index = 0;
		input->insert_mode = 1;
		return (1);
	}
	return (0);
}

void				ms_reader_write(t_ms_input *input, char *buff)
{
	s_del(&input->match);
	if (check_insertion(input))
	{
		ms_fresh_buff(input)[0] = buff[0];
		ms_erase_put(input, 1);
		ft_printf("\e[%dD", s_len(l_last(input->str_div)->content));
	}
	else if (buff[0])
	{
		if (input->insert_mode)
		{
			ms_fresh_buff(input)[0] = buff[0];
			ms_erase_put(input, 1);
			ft_printf("\e[%dD", s_len(l_last(input->str_div)->content));
		}
		else
			ms_fresh_buff(input)[0] = buff[0];
	}
}
