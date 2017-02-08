/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:17 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_map(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*new_list;

	new_list = l_new(lst->content, lst->index);
	new_list = f(new_list);
	lst = lst->next;
	while (lst)
	{
		l_push(&new_list, f(lst));
		lst = lst->next;
	}
	return (new_list);
}
