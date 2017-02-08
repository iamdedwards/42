/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_hop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:38:42 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			l_hop(t_list **this, t_list *newun)
{
	t_list			*yo;
	t_list			*former_next;

	yo = *this;
	former_next = yo->next;
	yo->next = newun;
	newun->next = former_next;
}

void			l_hop_if_arg(t_list **ref, t_list *newun,
int (*test)(void *, void *), void *arg)
{
	t_list			*lst;

	lst = *ref;
	if (test(lst->content, arg))
	{
		l_add(ref, newun);
		return ;
	}
	while (lst->next)
	{
		if (test(lst->next->content, arg))
			l_hop(&lst, newun);
		lst = lst->next;
	}
}

void			l_hop_if_s(t_list **ref, t_list *newun,
int (*test)(char *, char *), char *arg)
{
	t_list			*lst;

	lst = *ref;
	if (test(lst->content, arg))
	{
		l_add(ref, newun);
		return ;
	}
	while (lst->next)
	{
		if (test(lst->next->content, arg))
			l_hop(&lst, newun);
		lst = lst->next;
	}
}
