/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:10:33 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/19 14:44:10 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_list		*rm_not_dir(t_list *x)
{
	return ((x->index == 99) ? NULL : l_new_s(x->content));
}

static t_list		*filter_not_dir(t_list *x)
{
	return ((x->index == 99) ? l_new_s(x->content) : NULL);
}

static t_list		*get_unknown(t_list **dir_names)
{
	t_list			*unknown;
	t_list			*dir_trim;
	int				i;

	i = 0;
	unknown = l_filter(*dir_names, filter_not_dir);
	if (unknown)
	{
		dir_trim = l_filter(*dir_names, rm_not_dir);
		l_destroy(dir_names, 0);
		*dir_names = dir_trim;
	}
	return (unknown);
}

static void			handle_unknown(t_list **unknown, t_list *flags)
{
	t_list			*runner;
	t_list			*ls_info_list;
	t_list			*info_elem;

	if (!unknown || !*unknown)
		return ;
	ls_info_list = NULL;
	runner = *unknown;
	while (runner)
	{
		info_elem = l_new_ls_info(s_dup(runner->content),
		s_dup(runner->content), s_len(runner->content), flags);
		if (info_elem && LS_INFO_NODE(info_elem)->permissions[0] != 'd')
			l_push(&ls_info_list, info_elem);
		else if (info_elem)
		{
			ft_printf("ls: %s: permission denied\n",
			LS_INFO_NODE(info_elem)->filename);
			ls_info_del((t_ls_info **)&info_elem->content);
			x_del((void **)&info_elem);
		}
		runner = runner->next;
	}
	if (ls_info_list)
		put_info(0, ls_info_list, flags, 0);
}

int					main(int ac, char **av)
{
	t_list			*lav;
	t_list			*flags;
	t_list			*dir_names;
	t_list			*unknown;

	(void)ac;
	unknown = NULL;
	lav = l_init_sv(&av[1]);
	flags = get_flags(lav);
	dir_names = get_dirs(l_goto(lav, l_count(flags)));
	unknown = get_unknown(&dir_names);
	if (NULL == dir_names && NULL == unknown)
		dir_names = l_new_ls_info(s_dup("."), s_dup("."), -1, flags);
	else
		sort_dirs_initial(&dir_names, flags);
	handle_unknown(&unknown, flags);
	if (!dir_names)
		return (0);
	iterate_read2(&dir_names, flags,
	l_count(dir_names) + l_count(unknown) > 1);
	l_destroy(&lav, x_del);
	l_destroy(&flags, 0);
	l_destroy(&unknown, 0);
	return (0);
}
