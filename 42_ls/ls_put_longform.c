/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:10:33 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/05 10:16:15 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					get_usr_s_len(t_list *l)
{
	return (s_len(LS_INFO_NODE(l)->user_name));
}

int					get_grp_s_len(t_list *l)
{
	return (s_len(LS_INFO_NODE(l)->group_name));
}

int					get_size_s_len(t_list *l)
{
	return (s_len(LS_INFO_NODE(l)->size_str));
}

void				ls_printf_longform(t_list *info_list,
					int usr_s_len, int grp_s_len, int size_s_len)
{
	t_ls_info		*info;
	int				link_len;

	link_len = get_link_len(info_list);
	while (info_list)
	{
		info = info_list->content;
		ft_printf("%s %*d %-*s  %-*s",
		info->permissions, link_len, info->link_count, usr_s_len,
		info->user_name, grp_s_len, info->group_name);
		if (info->minor == -1)
			ft_printf("  %*s", size_s_len, info->size_str);
		else
			ft_printf(" %3d, %-4d", info->major, info->minor);
		ft_printf(" %8s %vc%s%vc%vc%vc\n",
			info->date_modified_str, info->colour, info->filename,
			(!s_equals(info->colour, "")) ? "\e[0m" : "",
			((info->sym_link_to) ? " -> " : ""),
			((info->sym_link_to) ? info->sym_link_to : ""));
		info_list = info_list->next;
	}
}

void				ls_put_longform(t_list *l, int hide, int faff)
{
	int				usr_s_len;
	int				grp_s_len;
	int				size_s_len;
	int				size;
	t_list			*run;

	usr_s_len = l_max_i(l, get_usr_s_len);
	grp_s_len = l_max_i(l, get_grp_s_len);
	size_s_len = l_max_i(l, get_size_s_len);
	if (!faff && (!(l_count(l) == 1 &&
	LS_INFO_NODE(l)->permissions[0] == 'l') && l_count(l)))
	{
		run = l;
		size = 0;
		while (run)
		{
			size += LS_INFO_NODE(run)->blocks;
			run = run->next;
		}
		ft_printf("total %d\n", size);
	}
	ls_printf_longform(l, usr_s_len, grp_s_len, size_s_len);
}
