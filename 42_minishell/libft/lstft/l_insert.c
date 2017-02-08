/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_insert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/01 17:00:05 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_insert(t_list **a, t_list *x, int pos)
{
	t_list			*run;
	t_list			*hold;

	if (!*a)
	{
		*a = x;
		return (*a);
	}
	if (pos == 0)
	{
		l_add(a, x);
		return (*a);
	}
	run = *a;
	while (run->next && pos--)
		run = run->next;
	if (pos)
	{
		hold = run->next;
		run->next = x;
		x->next = hold;
	}
	else
		run->next->next = x;
	return (*a);
}
