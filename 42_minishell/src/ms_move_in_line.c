/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_move_in_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:37 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:46 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_left(t_ms_input *input)
{
	if (input->insert_mode)
	{
		ms_reduce_current_buff(input);
		input->insert_mode = 0;
	}
	ms_erase_put(input, 0);
	if (input->insert_index < ms_buffs_len(input))
	{
		input->insert_index++;
	}
	if (input->insert_index)
		ft_printf("\e[%dD", input->insert_index);
	if (input->curr_pos)
	{
		input->curr_pos--;
	}
}

void				ms_right(t_ms_input *input)
{
	if (input->insert_mode)
	{
		ms_reduce_current_buff(input);
		input->insert_mode = 0;
	}
	ms_erase_put(input, 0);
	if (input->insert_index)
		ft_printf("\e[%dD", input->insert_index - 1);
	if (input->curr_pos < (int)s_len(ms_current_buff_node(input)->content))
	{
		input->curr_pos++;
	}
	if (input->insert_index)
		input->insert_index--;
}
