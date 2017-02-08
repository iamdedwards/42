/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_filter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/31 17:50:25 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_filter_sv(char **sv, t_list *(*f)(char *))
{
	int				i;
	t_list			*ret;
	t_list			*test;

	i = 0;
	ret = NULL;
	while (sv[i])
	{
		test = f(sv[i]);
		if (test)
			l_push_s(&ret, sv[i]);
		i++;
	}
	return (ret);
}

t_list			*l_filter_with(t_list *l,
	t_list *(*f)(t_list *, void *), void *args)
{
	t_list			*n;
	t_list			*tester;

	n = NULL;
	while (l)
	{
		if ((tester = f(l, args)))
		{
			l_push(&n, tester);
		}
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
