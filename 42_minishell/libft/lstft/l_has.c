/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_has.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/15 15:57:19 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				l_last_having(t_list *lst, int (*f)(void *))
{
	int				i;
	int				ret;

	i = 0;
	ret = -1;
	while (lst)
	{
		if (f(lst->content))
			ret = i;
		lst = lst->next;
		i++;
	}
	return (ret);
}

int				l_has(t_list *lst, int (*f)(void *))
{
	int				i;

	i = 1;
	while (lst)
	{
		if (f(lst->content))
			return (i);
		lst = lst->next;
		i++;
	}
	return (0);
}
