/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_previous.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:17 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_previous(t_list **list, t_list **ref)
{
	t_list			*a;
	t_list			*x;

	a = *list;
	x = *ref;
	while (a)
	{
		if (a->next == x)
			return (a);
		a = (a)->next;
	}
	return (NULL);
}
