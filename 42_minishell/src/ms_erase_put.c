/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_erase_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:31 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 12:23:17 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_put_buffs(t_ms_input *input)
{
	t_list			*run;

	run = input->str_div;
	while (run)
	{
		ps(run->content);
		run = run->next;
	}
}

int					ms_last_line_len(t_ms_input *input)
{
	int				i;
	int				len;
	int				last_line_len;
	int				line_count;

	last_line_len = 0;
	line_count = 1;
	i = (ms_get_cols() - ms_cursor_end_index(input)) + 1;
	len = s_len(ms_current_buff(input));
	while (i < len)
	{
		line_count++;
		i += ms_get_cols();
	}
	if ((line_count) > 1)
	{
		i -= ms_get_cols();
		last_line_len = s_len(&ms_current_buff(input)[i]);
	}
	else
	{
		last_line_len =
		s_len(ms_current_buff(input)) + ms_cursor_end_index(input);
	}
	return (last_line_len);
}

void				ms_erase_put(t_ms_input *input, int append_len)
{
	int				last_line_len;

	ft_printf("\e[u\e[0J");
	ms_put_buffs(input);
	if (input->select.values)
	{
		ms_refresh_selection_div(input);
		last_line_len = ms_last_line_len(input);
		ms_print_selection_grids(input, last_line_len);
		if (input->prompt_pos > tgetnum("li") - input->select.height)
		{
			ft_printf("\e[%dG\e[s\e[%dG", ms_cursor_end_index(input),
			last_line_len);
		}
	}
	if (append_len == -2)
		ft_printf("\e[u");
}
