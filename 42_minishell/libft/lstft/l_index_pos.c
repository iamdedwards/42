/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_index_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:17 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_find(t_list *x, size_t index)
{
	return (l_first_by_index(x, index));
}

int				l_index_pos(t_list *x, size_t index)
{
	size_t i;

	i = 0;
	while (x)
	{
		if (x->index == index)
			return (i);
		i++;
		x = x->next;
	}
	return (-1);
}
