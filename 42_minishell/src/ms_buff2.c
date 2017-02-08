/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_buff2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:29 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 16:58:26 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_buff_len_check(t_ms_input *input)
{
	char			*buff;
	char			*tmp;

	buff = l_goto(input->str_div, input->current_div)->content;
	if (input->curr_pos >= MS_BUFF_SIZE)
	{
		tmp = s_new(input->buff_allocs * MS_BUFF_SIZE + input->curr_pos);
		s_cpy(tmp, buff);
		s_del(&buff);
		l_goto(input->str_div, input->current_div)->content = tmp;
		input->buff_allocs++;
	}
}

char				*ms_fresh_buff(t_ms_input *input)
{
	char			*buff;

	ms_buff_len_check(input);
	buff = l_goto(input->str_div, input->current_div)->content;
	buff = &buff[input->curr_pos];
	input->curr_pos += 1;
	return (buff);
}

void				ms_alloc_buff(t_ms_input *input, char *content)
{
	input->curr_pos = 0;
	if (content)
		l_push_s(&input->str_div, content);
	else
		l_push_s(&input->str_div, s_new(MS_BUFF_SIZE));
}
