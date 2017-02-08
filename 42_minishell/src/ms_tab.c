/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:40 by dedwards          #+#    #+#             */
/*   Updated: 2017/02/08 15:13:02 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				fake_tab(t_ms_input *input)
{
	ms_append(input, MS_FAKE_TAB, 0);
	ms_erase_put(input, s_len(MS_FAKE_TAB));
}

void				ms_inc_curr_pos_by_tab(t_ms_input *input)
{
	int				inc;
	char			*buff;

	buff = &ms_current_buff(input)[input->curr_pos];
	inc = 0;
	while (buff[inc] && buff[inc] == ' ')
		inc++;
	while (buff[inc] && buff[inc] != ' ')
		inc++;
	while (buff[inc] && buff[inc] == ' ')
		inc++;
	input->insert_index -= inc;
	input->curr_pos += inc;
}

int					ms_tab_if_insert(t_ms_input *input)
{
	if (input->insert_mode)
	{
		ms_reduce_current_buff(input);
		ms_inc_curr_pos_by_tab(input);
		ms_erase_put(input, 0);
		if (input->insert_index)
			ft_printf("\e[%dD", input->insert_index);
		return (1);
	}
	else if (input->insert_index)
	{
		ms_inc_curr_pos_by_tab(input);
		ms_erase_put(input, 0);
		if (input->insert_index)
			ft_printf("\e[%dD", input->insert_index);
		return (1);
	}
	return (0);
}

void				ms_tab(t_ms_input *input)
{
	int				ret;
	char			*curr_buff;

	input->prompt_pos = ms_vertical_pos();
	curr_buff = ms_current_buff_node(input)->content;
	if (*s_tail(curr_buff, 1) == ' ' || s_len(curr_buff) == 0)
		return (fake_tab(input));
	if (ms_tab_if_insert(input))
		return ;
	if (input->select.values)
		ms_trunc_select(input);
	if (!s_has_other_than(curr_buff, " ") || (!s_haschar(curr_buff, ' ')))
		ms_find_command(input);
	else
	{
		ret = ms_complete_command(input);
		if (!ret || ret == -1)
		{
			ms_erase_put(input, 0);
			return (fake_tab(input));
		}
	}
}
