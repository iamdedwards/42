/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_reverse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:18 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_reverse(t_list **list)
{
	t_list			*head;
	t_list			*tail;
	t_list			*save;

	head = *list;
	tail = l_last(head);
	save = tail;
	while (tail != head)
	{
		tail->next = l_previous(&head, &tail);
		tail = tail->next;
	}
	tail->next = NULL;
	return (save);
}
