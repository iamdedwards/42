/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:15 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				l_add(t_list **alst, t_list *new)
{
	t_list			*head;
	t_list			*body;

	if (!new)
		return (0);
	if (!alst)
	{
		*alst = new;
	}
	else
	{
		head = new;
		body = *alst;
		head->next = body;
		*alst = head;
	}
	return (1);
}
