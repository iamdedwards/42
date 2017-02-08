/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_filter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:54:08 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_filter_with(t_list *l,
	t_list *(*f)(t_list *, void *), void *args)
{
	t_list			*n;
	t_list			*tester;

	n = NULL;
	while (l)
	{
		if ((tester = f(l, args)))
			l_push(&n, tester);
		l = l->next;
	}
	return (n);
}

t_list			*l_filter(t_list *l, t_list *(*f)(t_list *))
{
	t_list			*n;
	t_list			*tester;

	tester = NULL;
	n = NULL;
	while (l)
	{
		tester = f(l);
		if (tester != NULL)
		{
			l_push(&n, tester);
		}
		l = l->next;
	}
	return (n);
}
