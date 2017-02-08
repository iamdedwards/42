/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_reduce_buffs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:38 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:47 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_reduce_current_buff(t_ms_input *input)
{
	t_list			*run;
	char			*r_str;

	run = l_goto(input->str_div, input->current_div - 1);
	input->insert_index =
		s_len(run->next->next->content);
	r_str = s_format("{s}{s}{s}",
	run->content, run->next->content, run->next->next->content);
	s_cpy(run->content, r_str);
	s_del(&r_str);
	l_destroy(&run->next, x_del);
	input->current_div--;
}
