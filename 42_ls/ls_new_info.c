/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:53:37 by dan               #+#    #+#             */
/*   Updated: 2016/10/11 16:58:32 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			resolve_name(
					t_ls_info **info,
					char *initial_name, char *fullname, int *is_link)
{
	int				link_len;
	char			link_name[1024];

	(*info)->fullname = fullname;
	(*info)->filename = initial_name;
	buff_val(link_name, 0, 1024);
	link_len = readlink(fullname, link_name, 1023);
	if (link_name[0] == 0)
	{
		*is_link = 0;
	}
	else
	{
		*is_link = 1;
		(*info)->sym_link_to =
		sv_n_join((char *[]){"\e[3m", link_name, "\e[0m", 0}, 3);
	}
}

void				info_init(t_ls_info **info,
					t_list *flags, int filename_len)
{
	struct stat		stats;

	*info = (t_ls_info *)malloc(sizeof(t_ls_info));
	if (!*info)
	{
		TX("MEMORY ERROR");
	}
	(*info)->colour = "";
	(*info)->sym_link_to = NULL;
	(*info)->date_modified_str = NULL;
	(*info)->group_name = NULL;
	(*info)->user_name = NULL;
	(*info)->permissions = NULL;
	(*info)->size_str = NULL;
	(*info)->major = -1;
	(*info)->minor = -1;
	(*info)->filename_len = filename_len;
}

void				get_major_minor(t_ls_info **info, struct stat *stats)
{
	if (s_haschar("bc", (*info)->permissions[0]))
	{
		(*info)->minor = (minor(stats->st_rdev));
		(*info)->major = (major(stats->st_rdev));
	}
}

int					unreadable_dir(t_ls_info *info)
{
	if (s_inner(info->permissions, "d--"))
	{
		opendir(info->filename);
		ft_printf_fd(2, "ls: ");
		perror(info->filename);
		return (1);
	}
	return (0);
}

t_list				*l_new_ls_info(char *fullname,
					char *filename, int filename_len, t_list *flags)
{
	t_ls_info		*info;
	struct stat		stats;
	int				is_link;

	if (-1 == lstat(fullname, &stats))
	{
		ft_printf_fd(2, "ls: ");
		perror(fullname);
		return (NULL);
	}
	info_init(&info, flags, filename_len);
	resolve_name(&(info), filename, fullname, &is_link);
	ls_set_permissions(&(info), &stats, is_link);
	(info)->date_modified = stats.st_mtime;
	(info)->date_modified_spec = stats.st_mtimespec;
	ls_set_date(&(info)->date_modified_str, (info)->date_modified);
	(info)->user_name = s_dup(getpwuid(stats.st_uid)->pw_name);
	(info)->group_name = s_dup(getgrgid(stats.st_gid)->gr_name);
	info->link_count = stats.st_nlink;
	info->size = stats.st_size;
	info->size_str = i_to_s(stats.st_size);
	get_major_minor(&info, &stats);
	info->blocks = stats.st_blocks;
	return (l_new(info, sizeof(t_ls_info)));
}
