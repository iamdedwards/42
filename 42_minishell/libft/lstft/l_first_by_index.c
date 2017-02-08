/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_first_by_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/09/30 21:06:37 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_first_by_index(t_list *x, size_t index)
{
	while (x)
	{
		if (x->index == index)
			return (x);
		x = x->next;
	}
	return (NULL);
}
