/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/19 13:37:59 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*l_section_worker(t_list *l, char *s, int section_width)
{
	if (!s)
		return (l);
	if (s_len(s) - 1 < (unsigned int)section_width)
	{
		l_push(&l, l_new(s_n_dup(s, s_len(s)), sizeof(char *)));
		return (l);
	}
	l_push(&l, l_new(s_n_dup(s, section_width), sizeof(char *)));
	return (l_section_worker(l, &s[section_width], section_width));
}

t_list			*l_section(char *s, int section_width)
{
	t_list			*l;
	int				len;
	int				i;

	i = 0;
	len = s_len(s);
	l = NULL;
	return (l_section_worker(l, s, section_width));
}

static void		l_split_work(t_list **ref, char *s, char *split, int len)
{
	while (s_n_cmp(s, split, len) == 0)
	{
		l_push_s(ref, s_dup(split));
		s += len;
	}
}

t_list			*l_split(char *s, char *split)
{
	t_list			*list;
	int				len;
	int				i;

	i = 0;
	list = NULL;
	len = s_len(split);
	while (s[i])
	{
		i += s_nto_c(s, split[0]);
		if (s_n_cmp(&s[i], split, len) == 0)
		{
			if (list || i)
				l_push(&list, (i) ? l_new(s_n_dup(s, i), 0) : NULL);
			s += len + i;
			l_split_work(&list, s, split, len);
			i = -1;
		}
		i += (i <= 0) ? 1 : 0;
	}
	l_push(&list, (i) ? l_new(s_n_dup(s, i), 0) : NULL);
	return (list);
}

t_list			*l_dissect(char *s, char *split)
{
	t_list			*list;
	int				len;
	int				i;

	i = 0;
	list = NULL;
	len = s_len(split);
	while (s[i])
	{
		i += s_nto_c(s, split[0]);
		if (s_n_cmp(&s[i], split, len) == 0)
		{
			if (list || i)
				l_push(&list, (i) ? l_new(s_n_dup(s, i), 0) : NULL);
			s += len + i;
			i = -1;
		}
		i += (i <= 0) ? 1 : 0;
	}
	l_push(&list, (i) ? l_new(s_n_dup(s, i), 0) : NULL);
	return (list);
}
