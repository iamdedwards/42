/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:14:40 by dan               #+#    #+#             */
/*   Updated: 2016/08/03 16:33:26 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			is_time_sort(void *content)
{
	return (s_haschar(content, 't'));
}

static int			is_rev_sort(void *content)
{
	return (s_haschar(content, 'r'));
}

static t_list		*is_sort_flag(t_list *elem)
{
	char			*content;

	content = elem->content;
	if ((s_haschar(elem->content, 'r')) ||
	(s_haschar(elem->content, 't')))
		return (elem);
	return (NULL);
}

t_ls_sorters		get_ls_sorters(t_list *flags)
{
	int				time;
	int				rev;

	time = 0;
	rev = 0;
	time = l_has(flags, is_time_sort);
	rev = l_has(flags, is_rev_sort);
	if (!time && rev)
		return ((t_ls_sorters){ ls_alpha_sort_rev, 0 });
	if (time && !rev)
		return ((t_ls_sorters){ ls_alpha_sort, ls_time_sort });
	if (time && rev)
		return ((t_ls_sorters){ ls_alpha_sort_rev, ls_time_sort_rev });
	return ((t_ls_sorters){ ls_alpha_sort, 0 });
}

t_sorter			get_sorter(t_list *flags)
{
	int				time;
	int				rev;

	time = 0;
	rev = 0;
	time = l_has(flags, is_time_sort);
	rev = l_has(flags, is_rev_sort);
	if (!time && rev)
		return (ls_alpha_sort_rev);
	if (time && !rev)
		return (ls_time_sort);
	if (time && rev)
		return (ls_time_sort_rev);
	return (ls_alpha_sort);
}
