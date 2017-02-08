/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 15:04:37 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/11 16:56:12 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ls_process_entries2(DIR *dir_ptr,
					t_ls_info *info, t_list **ls_info_list, t_list *flags)
{
	char			*full_name;
	struct dirent	*entry;
	t_sorter		sorter;
	int				hide_secret;

	hide_secret = !l_has_c(flags, 'a') && !l_has_c(flags, 'A');
	sorter = get_sorter(flags);
	while ((entry = readdir(dir_ptr)) != NULL)
	{
		if (!(hide_secret && entry->d_name[0] == '.'))
		{
			if (!(l_has_c(flags, 'A') && (s_equals(entry->d_name, ".") ||
			s_equals(entry->d_name, ".."))))
			{
				full_name = sv_n_join((char *[]){
				info->fullname,
				(!(s_equals(info->filename, "/"))) ? "/" : "",
				entry->d_name, 0}, 3);
				l_push_sort_content(ls_info_list, l_new_ls_info(full_name,
				s_dup(entry->d_name), entry->d_namlen, flags), sorter);
			}
		}
	}
}

static void			ls_read_dir2(t_list **ls_info_list,
					t_ls_info *info, t_list *flags)
{
	t_list			*sort_flags;
	DIR				*dir_ptr;
	struct dirent	*entry;
	char			*full_name;

	dir_ptr = opendir(info->fullname);
	if (!dir_ptr)
	{
		ft_printf_fd(2, "ls: ");
		return (perror(info->filename));
	}
	ls_process_entries2(dir_ptr, info, ls_info_list, flags);
	closedir(dir_ptr);
}

static void			put_sym_link_long_info(t_ls_info **info, t_list *flags)
{
	t_list			*tmp;

	tmp = l_new(*info, 0);
	put_info((*info)->filename, tmp, flags, 0);
	l_destroy(&tmp, 0);
}

t_list				*ls_reader2(t_ls_info **info, t_list *flags, int is_multi)
{
	t_list			*ls_info_list;
	t_list			*sub_dirs;
	t_list			*tmp;

	sub_dirs = NULL;
	ls_info_list = NULL;
	if (l_has_c(flags, 'l') && (*info)->permissions[0] == 'l')
		put_sym_link_long_info(info, flags);
	else
	{
		ls_read_dir2(&ls_info_list, (*info), flags);
		put_info((*info)->fullname, ls_info_list, flags, is_multi);
	}
	ls_info_del(info);
	if (l_has_c(flags, 'R'))
	{
		if (!ls_info_list)
			return (NULL);
		sub_dirs = ls_get_sub_dirs2(info, &ls_info_list, flags);
	}
	l_destroy(&ls_info_list, (void (*)(void **))ls_info_del);
	return (sub_dirs);
}
