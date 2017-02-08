/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_replace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:56 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 19:11:24 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*s_replace(char **s, char *split, char *insert,
		int will_mem_destroy)
{
	t_list			*list;
	size_t			i;
	int				len;

	i = 0;
	len = s_len(split);
	list = NULL;
	while ((*s)[i] && !s_n_equals(&(*s)[i], split, len))
		i++;
	if (i == s_len(*s))
	{
		return (*s);
	}
	l_push(&list, l_new(s_n_dup(*s, i), sizeof(char *)));
	l_push(&list, l_new(s_dup(insert), sizeof(char *)));
	*s += i + len;
	l_push(&list, l_new(s_dup(*s), sizeof(char *)));
	if (will_mem_destroy)
	{
		free(*s);
	}
	return (lx_to_s(&list));
}

char			*s_dup_subber(char *s, char *split, char *insert)
{
	return (s_replace(&s, split, insert, 0));
}

char			*s_dup_subber_g(char *s, char *split, char *insert)
{
	char			*tmp;

	while (s_inner(s, split))
	{
		tmp = s;
		s = s_replace(&s, split, insert, 0);
		s_del(&tmp);
	}
	return (s);
}

void			s_subber(char **s, char *split, char *insert)
{
	*s = s_replace(s, split, insert, 1);
}

void			s_subber_g(char **s, char *split, char *insert)
{
	while (s_inner(*s, split))
		s_subber(s, split, insert);
}
