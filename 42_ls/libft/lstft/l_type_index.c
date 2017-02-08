/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_type_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:18 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_find(t_list *x, size_t type)
{
	return (l_first_by_type(x, type));
}

int				l_type_index(t_list *x, size_t type)
{
	size_t i;

	i = 0;
	while (x)
	{
		if (x->type == type)
			return (i);
		i++;
		x = x->next;
	}
	return (-1);
}
