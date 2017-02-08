/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_find_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:32 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:45 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_new_selection_execs_add_curr_files(t_ms_input *input,
					t_list **curr_files)
{
	t_list			*run;
	t_list			*cut;
	t_list			*end;

	if (*curr_files)
	{
		run = *curr_files;
		while (run->next)
		{
			end = l_last(run);
			cut = l_goto(run, -2);
			cut->next = NULL;
			l_push_sort_content(&input->select.values,
			end, ms_alpha_sort);
		}
		l_push_sort_content(&input->select.values, run, ms_alpha_sort);
	}
}

void				ms_new_selection_execs(t_ms_input *input)
{
	char			*curr_buff;
	t_list			*list;
	void			**params;

	input->select.start_index =
	s_len(ms_current_buff_node(input)->content);
	curr_buff = ms_current_buff_node(input)->content;
	params = (void *[]){curr_buff, (int[]){s_len(curr_buff)}};
	input->select.values =
	l_filter_with(input->ctx->binary_files, l_s_n_equals, params);
	list = l_filter_with(input->ctx->curr_files, l_s_n_equals, params);
	if (!input->select.values)
	{
		input->select.values = list;
		list = 0;
	}
	ms_new_selection_execs_add_curr_files(input, &list);
}

int					ms_find_command(t_ms_input *input)
{
	char			*selected;
	int				i;
	char			*curr_buff;

	if (!input->ctx->binary_files)
		return (0);
	curr_buff = ms_current_buff_node(input)->content;
	if (input->select.values == 0)
	{
		ms_new_selection_execs(input);
		if (!input->select.values)
			return (0);
	}
	selected = l_goto(input->select.values, input->select.selected)->content;
	i = 0;
	ms_overwrite(input, selected);
	ms_new_selection_div(input);
	ms_erase_put(input, s_len(selected));
	ms_next_selection(input);
	input->select_mode = 1;
	return (1);
}
