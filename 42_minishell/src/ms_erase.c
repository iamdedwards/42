/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:31 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 16:58:00 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_erase_if_insert(t_ms_input *input, int *target)
{
	if (input->insert_mode)
	{
		ms_reduce_current_buff(input);
		input->insert_mode = 0;
	}
	if (input->insert_index)
		(*target) -= input->insert_index;
}

int					ms_erase_if_fake_tab(t_ms_input *input,
					char *curr_buff, int target)
{
	if (target >= 3 && s_equals(&curr_buff[target - 3], MS_FAKE_TAB))
	{
		s_move(&curr_buff[target - 3], 4);
		input->curr_pos -= 4;
		ms_erase_put(input, -4);
		if (input->insert_index)
		{
			ft_printf("\e[%dD", input->insert_index);
		}
		return (1);
	}
	return (0);
}

void				ms_erase(t_ms_input *input)
{
	int				target;
	char			*curr_buff;

	target = s_len(ms_current_buff_node(input)->content) - 1;
	curr_buff = ms_current_buff_node(input)->content;
	ms_erase_if_insert(input, &target);
	if (ms_erase_if_fake_tab(input, curr_buff, target))
		return ;
	if (s_len(curr_buff) > 1 && target >= 0)
	{
		s_move(&curr_buff[target], 1);
	}
	else if (s_len(curr_buff) <= 1)
	{
		curr_buff[0] = 0;
		ms_erase_put(input, -1);
		if (input->curr_pos)
			input->curr_pos--;
		return ;
	}
	ms_erase_put(input, -1);
	if (input->insert_index)
		ft_printf("\e[%dD", input->insert_index);
	input->curr_pos--;
}
