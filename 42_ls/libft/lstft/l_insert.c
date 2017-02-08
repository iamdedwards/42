/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_insert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:17 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_insert(t_list **a, t_list *x, int pos)
{
	t_list			*o;
	t_list			*ho;

	if (l_count(*a) <= pos)
		return (NULL);
	if ((o = l_goto(*a, pos - 1)))
	{
		ho = o->next;
		o->next = x;
		x->next = ho;
	}
	else
		l_add(a, x);
	return (*a);
}
