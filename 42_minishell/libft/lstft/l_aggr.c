/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_aggr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:30:36 by dedwards          #+#    #+#             */
/*   Updated: 2016/09/19 13:57:10 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				l_sum_size(t_list *l, size_t (*getter)(t_list *l))
{
	size_t			size;

	size = 0;
	while (l)
	{
		size += getter(l);
		l = l->next;
	}
	return (size);
}

int					l_max_i(t_list *l, int (*getter)(t_list *l))
{
	int				size;
	int				test;

	size = (int)(MINOF(int));
	while (l)
	{
		test = getter(l);
		if (test > size)
			size = test;
		l = l->next;
	}
	return (size);
}
