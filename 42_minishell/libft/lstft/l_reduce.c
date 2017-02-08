/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_reduce_proto.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/15 14:30:15 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*l_reduce(t_list *a, void *init, void *(*f)(void *, void *))
{
	while (a)
	{
		init = f(init, a->content);
		a = a->next;
	}
	return (init);
}
