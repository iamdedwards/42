/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_month.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 19:01:37 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:34:52 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			dev_id(void)
{
	static int		g_id = 0;
	struct stat		devstats;

	if (g_id)
		return (g_id);
	stat("/dev/null", &devstats);
	g_id = devstats.st_dev;
	return (g_id);
}

void				ls_set_permissions(t_ls_info **info,
					struct stat *stats, int is_link)
{
	char			attrs[1024];
	int				fd;
	acl_t			acl;

	if (stats->st_mode > 4607 && stats->st_dev != dev_id())
	{
		buff_val(attrs, 0, 1023);
		fd = open((*info)->fullname, O_RDONLY);
		acl = acl_get_fd_np(fd, 256);
		close(fd);
		(*info)->permissions = permission_str(stats->st_mode,
			is_link, acl_valid(acl) != -1,
			listxattr((*info)->fullname, attrs, 1023, 0));
		acl_free(acl);
		if ((*info)->permissions[0] == 'l' &&
		listxattr((*info)->fullname, attrs, 1023, 1))
			s_tail((*info)->permissions, 1)[0] = '@';
		return ;
	}
	((*info)->permissions = permission_str(stats->st_mode, is_link, 0, 0));
	if (!s_haschar("bldp", *(*info)->permissions))
		*(*info)->permissions = 'c';
	if (stats->st_mode <= 4607)
		*(*info)->permissions = 'p';
}
