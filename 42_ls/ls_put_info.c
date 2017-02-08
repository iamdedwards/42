/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:57:57 by dan               #+#    #+#             */
/*   Updated: 2016/10/19 14:55:43 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ls_color(t_list **x)
{
	t_ls_info		*info;
	char			*tmp;

	info = CONTENT_OF_P(x, t_ls_info *);
	info->colour = EMPTY_STR;
	if (LS_DIFF)
		return ;
	else if (info->permissions[0] == 'd')
		info->colour = LS_DIR_COLOUR;
	else if (info->permissions[0] == 'l')
		info->colour = LS_LINK_COLOUR;
	else if (info->permissions[0] == '-')
		info->colour = LS_REG_COLOUR;
	else if (info->permissions[0] == 'b')
		info->colour = LS_BLOCK_DEVICE_COLOUR;
	else if (info->permissions[0] == 'c')
		info->colour = LS_DEVICE_COLOUR;
	else if (info->permissions[0] == 'p')
		info->colour = LS_PIPE_COLOUR;
	if (info->permissions[0] == '-' && info->permissions[3] == 'x')
		info->colour = LS_EXC_COLOUR;
}

void				ls_put_col(t_list *ls_info_list)
{
	t_list			*runner;

	runner = ls_info_list;
	while (runner)
	{
		ls_out_colour(runner, 0, 1);
		runner = runner->next;
	}
}

void				put_info(char *path, t_list *l, t_list *flags, int is_multi)
{
	int				is_recur;
	static	int		call_num = 0;

	is_recur = (l_has_c(flags, 'R'));
	if (!l_has_c(flags, 'N'))
	{
		each_l(&l, ls_color);
	}
	if (path && (call_num != 0 || is_multi))
		ft_printf("%vc%s:\n", (call_num != 0) ? "\n" : "", path);
	call_num++;
	if (l_has_c(flags, 'l'))
	{
		ls_put_longform(l, !l_has_c(flags, 'a'), path == 0);
	}
	else if (l_has_c(flags, '1'))
	{
		ls_put_col(l);
	}
	else
	{
		ls_grid(l, flags);
	}
}
