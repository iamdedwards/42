/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_iter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:54 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:06 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_iter(char *s, int (*f)(int))
{
	int				i;

	i = 0;
	while (s[i])
	{
		s[i] = f(s[i]);
		i++;
	}
	return (s);
}

void			l_s_iter(t_list **l_ref, int (*f)(int c))
{
	t_list			*l;

	l = *l_ref;
	while (l)
	{
		s_iter(l->content, f);
		l = l->next;
	}
}
