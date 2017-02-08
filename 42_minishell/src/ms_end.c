/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:30 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:43 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_end(t_ms_input *input)
{
	if (input->insert_mode)
	{
		ms_reduce_current_buff(input);
		input->insert_mode = 0;
	}
	input->insert_index = 0;
	ms_erase_put(input, 0);
	input->curr_pos = s_len(ms_current_buff_node(input)->content);
	input->insert_index = 0;
}
