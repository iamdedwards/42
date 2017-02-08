/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:36 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:45 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_home(t_ms_input *input)
{
	if (input->insert_mode)
	{
		ms_reduce_current_buff(input);
		input->insert_mode = 0;
	}
	input->insert_index = s_len(ms_current_buff_node(input)->content);
	input->curr_pos = 0;
	ms_erase_put(input, -2);
}
