/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:36 by dedwards          #+#    #+#             */
/*   Updated: 2017/02/08 15:15:14 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					history(t_ms_input *input, int mode)
{
	static int		pos = 0;
	char			*s;
	int				count;

	if (input->insert_mode)
		ms_reduce_current_buff(input);
	count = l_count(input->ctx->history);
	if (count == 0)
	{
		ms_erase_put(input, 0);
		return (0);
	}
	if (pos < 0)
		pos = count - 1;
	if ((count - 1 - pos) < 0)
		pos = 0;
	s = (l_goto(input->ctx->history, count - 1 - pos)->content);
	ms_clear_buffs(input);
	ms_overwrite(input, s);
	input->curr_pos = s_len(
	ms_current_buff_node(input)->content);
	input->insert_index = 0;
	input->insert_mode = 0;
	pos += mode;
	ms_erase_put(input, s_len(s));
	return (1);
}

void				ms_up(t_ms_input *input)
{
	(history(input, 1));
}

void				ms_down(t_ms_input *input)
{
	(history(input, -1));
}
