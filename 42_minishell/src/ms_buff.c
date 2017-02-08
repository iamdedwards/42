/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:29 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 16:58:18 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list				*ms_current_buff_node(t_ms_input *input)
{
	return (l_goto(input->str_div, input->current_div));
}

char				*ms_current_buff(t_ms_input *input)
{
	return (ms_current_buff_node(input)->content);
}

void				ms_append(t_ms_input *input, char *s, int offset)
{
	int				i;

	i = 0;
	input->curr_pos += offset;
	ms_buff_len_check(input);
	while (s[i])
	{
		ms_fresh_buff(input)[0] = s[i++];
	}
}

void				ms_overwrite(t_ms_input *input, char *s)
{
	char			*buff;

	buff = ms_current_buff(input);
	s_clear(buff, input->buff_allocs * MS_BUFF_SIZE);
	input->curr_pos = 0;
	ms_append(input, s, 0);
}

void				ms_clear_buffs(t_ms_input *input)
{
	t_list			*str_div;

	str_div = input->str_div;
	s_clear(str_div->content, MS_BUFF_SIZE);
	if (str_div->next)
	{
		l_destroy(&str_div->next, x_del);
		input->str_div->next = 0;
	}
}
