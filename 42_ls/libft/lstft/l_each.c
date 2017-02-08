/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_each.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/14 14:16:05 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			each_l(t_list **x, void (*f)(t_list **))
{
	t_list			*lst;

	lst = *x;
	while (lst)
	{
		f(&(lst));
		lst = lst->next;
	}
}

void			each_l_using(t_list **x, void (*f)(t_list **, void *),
		void *args)
{
	t_list			*lst;

	lst = *x;
	while (lst)
	{
		f(&(lst), args);
		lst = lst->next;
	}
}

void			each_li(t_list **x, void (*f)(void **, int))
{
	t_list			*lst;
	int				i;

	i = 0;
	lst = *x;
	while (lst)
	{
		f(&(lst->content), i++);
		lst = lst->next;
	}
}

void			iter_l_content(t_list *x, void (*f)(void *))
{
	while (x)
	{
		f(x->content);
		x = x->next;
	}
}

int				wherein_l_content(t_list *x,
				int (*f)(void *, void *), void *arg)
{
	while (x)
	{
		if (f(x->content, arg))
			return (1);
		x = x->next;
	}
	return (0);
}
