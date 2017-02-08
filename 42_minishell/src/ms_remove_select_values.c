/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_remove_select_values.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:39 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:47 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_destroy_select_grids(t_ms_input *input)
{
	t_list			*run;
	char			**sv;

	run = input->select.value_grids;
	while (run)
	{
		sv = (char **)run->content;
		sv_del(&sv);
		run = run->next;
	}
	if (input->select.value_grids)
		l_destroy(&input->select.value_grids, 0);
}

void				ms_destroy_select_values(t_ms_input *input)
{
	l_destroy(&input->select.values, x_del);
	l_destroy(&input->select.value_grids, x_del);
}

int					ms_remove_select_values(t_ms_input *input)
{
	if (input->select_mode)
	{
		input->select.selected = 0;
		ft_printf("\e[0J");
		input->select_mode = 0;
		return (1);
	}
	return (0);
}

void				ms_trunc_select(t_ms_input *input)
{
	char	*buff;
	int		init_len;
	int		select_len;

	if (!input->select.values)
		return ;
	buff = ms_current_buff_node(input)->content;
	select_len = s_len(buff);
	init_len = input->select.start_index;
	if (select_len - init_len > 0)
		s_clear(&buff[init_len], select_len - init_len);
	else
		s_clear(&buff[0], s_len(buff));
	input->curr_pos -= select_len - init_len;
}
