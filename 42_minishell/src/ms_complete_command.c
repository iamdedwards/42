/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_complete_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:30 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 16:01:10 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*ms_define_last_word(char *s, int *start, int *end)
{
	int				i;
	int				trailing_space;

	if (!s_haschar(s, ' ') && !s_haschar(s, '\t'))
		return (s);
	trailing_space = *s_tail(s, 1) == ' ' || *s_tail(s, 1) == '\t';
	while ((' ' == *s_tail(s, trailing_space))
	|| (' ' == *s_tail(s, trailing_space)))
	{
		trailing_space++;
	}
	i = s_len(s) - (1 + trailing_space);
	while (i && (s[i] != ' ' && s[i] != '\t'))
	{
		pc(s[i]);
		i--;
	}
	*end = s_len(&s[i + 1]) - trailing_space;
	*start = i + 1;
	return (&s[i + 1]);
}

void				ms_new_selection_curr_files_inner(t_ms_input *input,
					int word_start, int word_len)
{
	char			*search;
	char			*search_alloc;

	search = ms_current_buff_node(input)->content;
	search = &search[word_start];
	search_alloc = s_n_dup(search, word_len);
	input->select.values = l_filter_with(input->ctx->curr_files,
			l_s_inner, search_alloc);
	s_del(&search_alloc);
}

t_list				*l_sdup(t_list *y)
{
	t_list			*x;

	x = 0;
	while (y)
	{
		l_push_s(&x, s_dup(y->content));
		y = y->next;
	}
	return (x);
}

void				ms_new_selection_curr_files(t_ms_input *input)
{
	char			*curr_buff;
	int				word_start;
	int				word_len;
	void			**params;

	curr_buff = ms_current_buff_node(input)->content;
	ms_define_last_word(curr_buff, &word_start, &word_len);
	params = (void *[]){&curr_buff[word_start], &word_len};
	input->select.values = l_filter_with(input->ctx->curr_files,
		l_s_n_equals, params);
	if (!input->select.values)
	{
		ms_new_selection_curr_files_inner(input, word_start, word_len);
	}
	input->select.start_index = word_start;
	input->select.len = word_len;
}

int					ms_complete_command(t_ms_input *input)
{
	char			*curr_buff;
	char			*selected;
	int				i;

	i = 0;
	curr_buff = ms_current_buff_node(input)->content;
	if (!input->select.values)
	{
		ms_new_selection_curr_files(input);
	}
	if (!input->select.values)
	{
		return (-1);
	}
	selected = l_goto(input->select.values, input->select.selected)->content;
	ms_append(input, selected, -input->select.len);
	input->select.len = 0;
	ms_new_selection_div(input);
	ms_erase_put(input, s_len(selected));
	ms_next_selection(input);
	input->select_mode = 1;
	return (1);
}
