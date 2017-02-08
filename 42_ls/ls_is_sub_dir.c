/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sub_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 22:17:06 by dan               #+#    #+#             */
/*   Updated: 2016/08/05 15:29:16 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ls_is_sub_dir(t_list *ls_info_list)
{
	t_ls_info *info;

	info = (t_ls_info *)ls_info_list->content;
	if ((info->permissions[0] == 'd'
	&& !s_equals(info->filename, "."))
	&& !s_equals(info->filename, ".."))
	{
		return (l_new((info), sizeof(t_ls_info)));
	}
	return (NULL);
}
