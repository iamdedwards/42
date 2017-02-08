/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_remove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/05 16:10:31 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*l_where(t_list **a_ref, int (*test)(t_list *))
{
	t_list *runner;

	runner = *a_ref;
	while (runner)
	{
		if (test(runner))
			return (runner);
		(runner) = (runner)->next;
	}
	return (NULL);
}

void	l_remove_if(t_list **a_ref, int (*test)(t_list *), void (*f)(void **))
{
	t_list			*grab;
	t_list			*ret;

	grab = *a_ref;
	ret = NULL;
	while (grab)
	{
		if (!(l_where(a_ref, test)))
			l_push(&ret, l_new(grab->content, grab->index));
		grab = grab->next;
	}
	l_destroy(a_ref, f);
	*a_ref = ret;
}

void	l_remove(t_list **a_ref, t_list **element_ref, void (*f)(void **))
{
	int				element_index;
	t_list			*grab;

	element_index = l_refindex(a_ref, element_ref);
	grab = (l_grab(a_ref, element_index));
	if (f)
		f(&grab->content);
	x_del((void **)&grab);
}
