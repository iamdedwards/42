/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_iterate_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:29:54 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 13:06:52 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			pop_single(t_list **subs_next, t_ls_info **info)
{
	t_list			*tmp;

	tmp = l_grab((t_list **)&(*subs_next)->content, 0);
	*info = ((t_list *)tmp)->content;
	free(tmp);
}

static void			pop_list(t_list **subs_next, t_ls_info **info)
{
	t_list			*tmp;

	tmp = l_grab(&(*subs_next), 0);
	*info = ((t_list *)tmp->content)->content;
	free(tmp->content);
	free(tmp);
}

void				iterate_read2(t_list **dirs,
					t_list *flags, int is_multi)
{
	t_list			*subs;
	t_list			*subs_next;
	t_ls_info		*info;
	t_list			*tmp;

	subs_next = NULL;
	if (!dirs)
		return ;
	info = (*dirs)->content;
	subs = ls_reader2(&info, flags, is_multi);
	while (info)
	{
		if (subs && (!(subs_next && subs_next->content == subs)))
			l_add(&subs_next, l_new(subs, 0));
		subs = ls_reader2(&info, flags, is_multi);
		if ((!info && subs_next) && (l_count(subs_next->content) > 1))
			pop_single(&subs_next, &info);
		else if (!info && subs_next)
			pop_list(&subs_next, &info);
	}
	tmp = l_grab(dirs, 0);
	x_del((void **)&tmp);
	if (*dirs)
		iterate_read2(dirs, flags, is_multi);
}
