/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sformtest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 11:44:46 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/19 14:59:16 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ls_filename_len(t_list *l)
{
	int				len;

	len = (CONTENT_OF(l, t_ls_info *)->filename_len);
	if (len == -1)
		len = (s_len(LS_INFO_NODE(l)->filename));
	return (len);
}

void				ls_grid(t_list *ls_info_list, t_list *flags)
{
	size_t			min_width;
	t_list			*widths;
	size_t			ls_cols_width;
	int				height;
	float			height_float;

	ls_cols_width = ls_get_cols();
	min_width = l_max_i(ls_info_list, ls_filename_len);
	height_float = (l_count(ls_info_list) * min_width) / ls_get_cols();
	if (height_float > 1)
	{
		height = f_to_i(height_float);
		height = (!height) ? 1 : height;
	}
	else
	{
		height = 1;
	}
	if (min_width)
		ls_put_grid(ls_info_list, height, min_width);
}

void				ls_out_colour(t_list *runner, int min_width, int no_grid)
{
	char			*tmp;

	tmp = s_join(LS_INFO_NODE(runner)->filename,
	(LS_INFO_NODE(runner)->colour[0]) ? LS_END_COLOUR : "");
	ft_printf("%vc%-*s%vc",
	LS_INFO_NODE(runner)->colour,
	(no_grid) ? 0 :
	min_width + (4 * (0 != LS_INFO_NODE(runner)->colour[0])) + 1,
	tmp,
	(no_grid) ? "\n" : "");
	s_del(&tmp);
}

void				ls_put_grid(
					t_list *ls_info_list, int height, int min_width)
{
	int				i;
	int				y;
	t_list			*runner;

	runner = ls_info_list;
	i = 0;
	y = 1;
	while (y <= height)
	{
		while (runner)
		{
			if (i % height == 0)
				ls_out_colour(runner, min_width, 0);
			runner = runner->next;
			i++;
		}
		ft_printf("\n");
		runner = l_goto(ls_info_list, y++);
		i = 0;
	}
}
