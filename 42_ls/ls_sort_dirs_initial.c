/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dirs_initial.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 13:31:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/09/20 18:10:08 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list		*sort_dirs_iter(t_list **dirs,
					t_list *flags, t_sorter sorter)
{
	t_list			*runner;
	int				error;
	t_list			*dirs_sorted;

	dirs_sorted = NULL;
	runner = *dirs;
	while ((runner))
	{
		l_push_sort_content(&dirs_sorted,
		l_new_ls_info(s_dup((runner)->content),
		s_dup((runner)->content), -1, flags), sorter);
		(runner) = (runner)->next;
	}
	return (dirs_sorted);
}

void				sort_dirs_initial(t_list **dirs, t_list *flags)
{
	t_list			*runner;
	t_sorter		sorter;
	t_list			*dirs_sorted;

	dirs_sorted = NULL;
	sorter = (l_has_c(flags, 'r')) ? ls_alpha_sort_rev : ls_alpha_sort;
	runner = *dirs;
	if (l_count(*dirs) == 1)
	{
		dirs_sorted =
		l_new_ls_info(s_dup((*dirs)->content),
		s_dup((*dirs)->content), -1, flags);
		l_destroy(dirs, 0);
		*dirs = dirs_sorted;
	}
	else
	{
		dirs_sorted = sort_dirs_iter(dirs, flags, sorter);
		l_destroy(dirs, 0);
		*dirs = dirs_sorted;
	}
}
