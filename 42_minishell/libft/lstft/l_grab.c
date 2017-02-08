/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_grab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/11 18:26:29 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_grab(t_list **x, int i)
{
	t_list			*z;
	t_list			*y;

	if (i < 1)
	{
		y = *x;
		*x = (*x)->next;
		y->next = NULL;
		return (y);
	}
	y = l_goto(*x, i);
	z = l_goto(*x, i - 1);
	z->next = z->next->next;
	y->next = NULL;
	return (y);
}
