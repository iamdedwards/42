/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_push_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:35:25 by dan               #+#    #+#             */
/*   Updated: 2016/07/27 13:49:20 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	l_push_sort_content(t_list **ref,
					t_list *newl, int (*sorter_ref)(void *, void *))
{
	t_list	*run;
	t_list	*hold;
	int		ret;

	if (!newl)
		return (-1);
	if (!ref || !*ref)
		return (l_push(ref, newl));
	run = *ref;
	ret = (sorter_ref(newl->content, run->content));
	if (ret == -1 || ret == 0)
		return (l_add(ref, newl));
	while (run->next && sorter_ref(newl->content, run->next->content) == 1)
		run = run->next;
	if (run->next)
	{
		hold = run->next;
		run->next = newl;
		newl->next = hold;
		return (1);
	}
	else
		return (l_push(ref, newl));
}

int	l_push_sort(t_list **ref,
					t_list *newl, int (*sorter_ref)(t_list *, t_list *))
{
	t_list	*run;
	t_list	*hold;
	int		ret;

	if (!newl)
		return (-1);
	if (!ref || !*ref)
		return (l_push(ref, newl));
	run = *ref;
	ret = (sorter_ref(newl, run));
	if (ret == -1 || ret == 0)
		return (l_add(ref, newl));
	while (run->next && sorter_ref(newl, run->next) == 1)
		run = run->next;
	if (run->next)
	{
		hold = run->next;
		run->next = newl;
		newl->next = hold;
		return (1);
	}
	else
		return (l_push(ref, newl));
}
