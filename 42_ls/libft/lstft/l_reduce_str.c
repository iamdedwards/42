/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_reduce_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/03 10:15:45 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				each_s_len(t_list *a)
{
	int				len;

	len = 0;
	while (a)
	{
		len += s_len(a->content);
		a = a->next;
	}
	return (len);
}

static char		*l_to_s_proto(t_list **a, int ifdel)
{
	int				len;
	char			*s;
	t_list			*run;

	run = *a;
	len = each_s_len(*a);
	s = s_new(len);
	while ((run))
	{
		s_cpy(&s[s_len(s)], (run)->content);
		(run) = (run)->next;
	}
	if (ifdel == 1)
		l_destroy((a), x_del);
	else if (ifdel == 0)
		l_destroy((a), 0);
	return (s);
}

char			*lx_to_s(t_list **a)
{
	return (l_to_s_proto(a, 0));
}

char			*lxx_to_s(t_list **a)
{
	return (l_to_s_proto(a, 1));
}

char			*l_to_s(t_list *a)
{
	return (l_to_s_proto(&a, -1));
}
