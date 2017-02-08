/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_next_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:38 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:46 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_next_selection(t_ms_input *input)
{
	input->select.selected++;
	if (l_count(input->select.values) - 1 < input->select.selected)
	{
		input->select.selected = 0;
	}
	if (input->select.div_count != -1)
	{
		if (input->select.selected % input->select.div_count == 0)
			input->select.current_value_grid++;
		if (l_count(input->select.value_grids) ==
				input->select.current_value_grid)
		{
			input->select.current_value_grid = 0;
			input->select.selected = 0;
		}
	}
}
