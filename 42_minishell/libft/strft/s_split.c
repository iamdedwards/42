/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:56 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/31 10:25:37 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**lx_to_sv(t_list **x_ref)
{
	char			**strs;
	int				i;
	t_list			*x;

	x = *x_ref;
	i = 0;
	strs = (char **)malloc(sizeof(char *) * l_count(x) + 1);
	while (x)
	{
		strs[i] = x->content;
		x = x->next;
		i++;
	}
	strs[i] = 0;
	l_destroy(x_ref, 0);
	return (strs);
}

char			**s_split(char *s, char *split)
{
	t_list			*list;

	list = l_split(s, split);
	return (lx_to_sv(&list));
}

char			**s_dissect(char *s, char *split)
{
	t_list			*list;

	list = l_dissect(s, split);
	return (lx_to_sv(&list));
}
