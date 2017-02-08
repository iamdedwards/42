/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_create_selection_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:30 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:10:08 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ms_filename_len(t_list *x)
{
	return (s_len(x->content) + 5);
}

void				ms_create_selection_array(t_ms_input *input, t_list *values,
					int get_width)
{
	int				i;
	int				j;
	int				y;
	t_list			*runner;
	char			**array;

	(void)get_width;
	if (!values)
		return ;
	array = (char **)malloc(sizeof(char *) * l_count(values) + 1);
	i = 0;
	y = 1;
	j = 0;
	runner = values;
	input->select.width =
	f_to_i((float)l_count(values) / (float)input->select.height);
	if (input->select.width * input->select.min_width > ms_get_cols())
		input->select.width = 1;
	while (runner)
	{
		array[j++] = runner->content;
		runner = runner->next;
	}
	array[j] = 0;
	l_push(&input->select.value_grids, l_new(array, 0));
}

void				ms_calc_selection_height(t_ms_input *input, t_list *values)
{
	int				width;
	float			height_float;

	width = ms_get_cols();
	width -= (width / 100) * 42;
	input->select.min_width = l_max_i(values, ms_filename_len);
	input->select.width = -1;
	height_float = (float)l_count(values);
	height_float *= (float)input->select.min_width;
	height_float /= (float)width;
	input->select.height = 1;
	if (height_float > 1)
	{
		input->select.height = f_to_i(height_float);
		input->select.height =
			(!input->select.height) ? 1 : input->select.height;
	}
}
