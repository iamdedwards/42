/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/17 14:38:54 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				l_push_s(t_list **alst, char *s)
{
	return (l_push(alst, l_new_s(s)));
}

int				l_push_sv(t_list **alst, char **sv)
{
	int				i;
	int				ret;

	i = 0;
	while (sv[i])
	{
		ret = l_push(alst, l_new_s(sv[i]));
		i++;
	}
	return (ret);
}

int				l_push(t_list **alst, t_list *newl)
{
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = *alst;
	if (!newl)
		return (-1);
	if (!(tmp))
	{
		*alst = newl;
		return (0);
	}
	while ((*alst)->next)
	{
		(*alst) = (*alst)->next;
		i++;
	}
	(*alst)->next = newl;
	*alst = tmp;
	return (i);
}
