/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_goto.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/17 14:31:23 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_goto(t_list *lst, int pos)
{
	if (pos < 0)
	{
		pos = -pos;
		return (l_goto(lst, l_count(lst) - pos));
	}
	while (lst && pos--)
	{
		lst = lst->next;
	}
	return (lst);
}
