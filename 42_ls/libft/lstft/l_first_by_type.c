/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_first_by_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:16 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_first_by_type(t_list *x, size_t type)
{
	while (x)
	{
		if (x->type == type)
			return (x);
		x = x->next;
	}
	return (NULL);
}
