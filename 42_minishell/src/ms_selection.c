/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_selection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:39 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 12:23:38 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ms_print_selection_grids(t_ms_input *input,
					int last_line_len)
{
	char			**grid;
	t_list			*run;
	int				i;
	char			*selected;
	int				up;

	up = 0;
	run = l_goto(input->select.value_grids, input->select.current_value_grid);
	selected = l_goto(input->select.values, input->select.selected)->content;
	grid = run->content;
	i = 0;
	while (grid[i])
	{
		if (i % input->select.width == 0)
		{
			ps("\n");
			up++;
		}
		if (s_equals(grid[i], selected))
			ps("\e[7m");
		ft_printf("%-*s\e[0m", input->select.min_width, grid[i]);
		i++;
	}
	ft_printf("\e[%dA\e[%dG", up, last_line_len);
}

void			ms_new_selection_div_if_no_space(t_ms_input *input)
{
	int				div_height;
	int				div_count;
	t_list			*div;
	int				pos;
	int				get_width;

	div_height = input->select.height / (tgetnum("li") / 3);
	div_count = l_count(input->select.values) / div_height;
	pos = 0;
	input->select.height = div_height;
	while (div_height--)
	{
		div = (l_n_dup(l_goto(input->select.values, pos), div_count));
		ms_calc_selection_height(input, div);
		ms_create_selection_array(input, div, get_width == 1);
		l_destroy(&div, 0);
		get_width = 0;
		pos += div_count;
	}
	input->select.div_count = div_count;
}

void			ms_new_selection_div(t_ms_input *input)
{
	ms_calc_selection_height(input, input->select.values);
	input->select.width = 0;
	if (input->select.height > tgetnum("li") / 3)
	{
		ms_new_selection_div_if_no_space(input);
	}
	else
	{
		input->select.div_count = -1;
		ms_create_selection_array(input, input->select.values, 1);
	}
	input->select.term_width_at_creation = ms_get_cols();
}

void			ms_refresh_selection_div(t_ms_input *input)
{
	int				redo;

	redo = !input->select.values;
	redo += input->select.term_width_at_creation != ms_get_cols();
	if (redo)
	{
		if (input->select.value_grids)
		{
			l_destroy(&input->select.value_grids, 0);
		}
		ms_new_selection_div(input);
	}
}
