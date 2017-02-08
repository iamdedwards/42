/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_refindex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:18 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				l_refindex(t_list **list, t_list **ref)
{
	t_list			*a;
	t_list			*x;
	int				i;

	i = 0;
	a = *list;
	x = *ref;
	while (a)
	{
		if (a == x)
			return (i);
		i++;
		a = (a)->next;
	}
	return (-1);
}
