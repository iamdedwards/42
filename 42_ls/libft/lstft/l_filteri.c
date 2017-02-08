/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_filteri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 17:39:13 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_filteri(t_list *l,
		t_list *(*f)(t_list *, int))
{
	t_list			*n;
	t_list			*tester;
	int				i;

	n = NULL;
	i = 0;
	while (l)
	{
		if ((tester = f(l, i)))
		{
			l_push(&n, tester);
		}
		i++;
		l = l->next;
	}
	return (n);
}
