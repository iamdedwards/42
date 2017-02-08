/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_link_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 13:31:37 by dedwards          #+#    #+#             */
/*   Updated: 2016/09/20 19:17:26 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					get_link_len(t_list *l)
{
	char			c;
	int				perm_len;
	int				link_len;

	link_len = 2;
	while (l)
	{
		perm_len = s_len(LS_INFO_NODE(l)->permissions);
		if (link_len == 2 && LS_INFO_NODE(l)->permissions[perm_len - 1] != ' ')
			link_len++;
		if (link_len < 3 && LS_INFO_NODE(l)->link_count > 99)
			link_len++;
		if (link_len < 4 && LS_INFO_NODE(l)->link_count > 999)
			link_len++;
		if (link_len < 5 && LS_INFO_NODE(l)->link_count > 9999)
			link_len++;
		l = l->next;
	}
	return (link_len);
}
