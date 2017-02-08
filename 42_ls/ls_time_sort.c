/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_time_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:01:22 by dan               #+#    #+#             */
/*   Updated: 2016/09/20 13:34:53 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ls_time_sort_proto(void *curr, void *next, int rev)
{
	t_ls_info		*info_next;
	t_ls_info		*info_curr;

	info_curr = (t_ls_info *)curr;
	info_next = (t_ls_info *)next;
	if (info_curr->date_modified_spec.tv_sec <
	info_next->date_modified_spec.tv_sec)
		return ((rev) ? -1 : 1);
	if (info_curr->date_modified_spec.tv_sec >
	info_next->date_modified_spec.tv_sec)
		return ((rev) ? 1 : -1);
	if (info_curr->date_modified_spec.tv_nsec <
	info_next->date_modified_spec.tv_nsec)
		return ((rev) ? -1 : 1);
	if (info_curr->date_modified_spec.tv_nsec >
	info_next->date_modified_spec.tv_nsec)
		return ((rev) ? 1 : -1);
	return (ls_alpha_sort_proto(curr, next, rev));
}

int				ls_time_sort_rev(void *curr, void *next)
{
	return (ls_time_sort_proto(curr, next, 1));
}

int				ls_time_sort(void *curr, void *next)
{
	return (ls_time_sort_proto(curr, next, 0));
}
