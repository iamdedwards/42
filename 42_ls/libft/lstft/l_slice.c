/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_slice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 13:40:00 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/26 11:37:05 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			l_del_from(t_list **lst, int untill)
{
	t_list *yep;

	yep = l_goto(*lst, untill);
	l_destroy(&yep, 0);
}

t_list			*l_n_dup(t_list *lst, int untill)
{
	t_list *dup;

	dup = 0;
	while (untill-- && lst)
	{
		l_push_s(&dup, lst->content);
		lst = lst->next;
	}
	return (dup);
}
