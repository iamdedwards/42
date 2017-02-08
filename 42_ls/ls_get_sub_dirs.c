/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_sub_dirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 13:14:14 by dedwards          #+#    #+#             */
/*   Updated: 2016/09/20 18:13:47 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				sort_sub_dirs(t_list **sub_dirs, t_list *flags)
{
	t_list			*runner;
	t_sorter		sorter;
	t_list			*dirs_sorted;

	dirs_sorted = NULL;
	if (sub_dirs == 0 || *sub_dirs == 0)
		return ;
	dirs_sorted = NULL;
	sorter = (l_has_c(flags, 'r')) ? ls_alpha_sort_rev : ls_alpha_sort;
	runner = *sub_dirs;
	while (runner)
	{
		l_push_sort_content(&dirs_sorted,
		l_new(runner->content, runner->index), sorter);
		runner = runner->next;
	}
	l_destroy(sub_dirs, 0);
	*sub_dirs = dirs_sorted;
}

int					ls_not_sub_dir(t_list *ls_info_list)
{
	t_ls_info *info;

	info = (t_ls_info *)ls_info_list->content;
	if ((info->permissions[0] == 'd'
	&& !s_equals(info->filename, "."))
	&& !s_equals(info->filename, ".."))
	{
		return (0);
	}
	return (1);
}

t_ls_info			*ls_info_dir(t_ls_info *info)
{
	t_ls_info		*clone;

	clone = (t_ls_info *)malloc(sizeof(t_ls_info));
	*clone = (t_ls_info){0};
	clone->filename = s_dup(info->filename);
	clone->fullname = s_dup(info->fullname);
	clone->date_modified = info->date_modified;
	clone->permissions = s_dup("d");
	return (clone);
}

t_list				*ls_get_sub_dirs2(t_ls_info **info,
					t_list **ls_info_list, t_list *flags)
{
	t_list			*x;
	t_list			*grab;
	t_list			*ret;

	ret = NULL;
	x = *ls_info_list;
	while (*ls_info_list)
	{
		if ((*ls_info_list) && !ls_not_sub_dir((*ls_info_list)))
		{
			if (!*info)
				*info = ls_info_dir(LS_INFO_NODE(*ls_info_list));
			else
			{
				l_push(&ret,
				l_new(ls_info_dir(LS_INFO_NODE(*ls_info_list)),
				sizeof(t_ls_info)));
			}
		}
		(*ls_info_list) = (*ls_info_list)->next;
	}
	*ls_info_list = x;
	sort_sub_dirs(&ret, flags);
	return (ret);
}
