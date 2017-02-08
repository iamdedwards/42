/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_color_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 15:27:45 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			put_lst_color(t_list *l)
{
	char			key;

	key = '3';
	while (l)
	{
		if (key < '5' && put_if_mapped(l->content, key, color_map(), 'm'))
			key++;
		else if (s_haschars(l->content, "()"))
		{
			if (s_inner(l->content, "rgb"))
			{
				sf_put_rgb(l->content, (key < '5') ? key : 0);
				key++;
			}
			put_func_if_mapped(l->content);
		}
		else
		{
			if (0[(char *)l->content] == '.')
				put_if_mapped(&1[(char *)l->content], '2', style_map(), 'm');
			else
				put_if_mapped(l->content, '\0', style_map(), 'm');
		}
		l = l->next;
	}
}

char				*shortcode_replace(char *btw, int len)
{
	int					i;
	static t_s_s_map	map[] = {
		{".", "\e[0m"},
		{"orange", "{rgb(255, 127, 0)}"},
		{"pink", "{rgb(255, 20, 147)}"},
		{0, 0},
	};

	i = 0;
	while ((map)[i].value)
	{
		if (s_n_equals((map)[i].key, btw, len))
			return ((map)[i].value);
		i++;
	}
	return (0);
}

void				escape_code_put(char *btw, int len)
{
	char			*key;
	t_list			*split;
	char			*tmp;

	if ((tmp = shortcode_replace(btw, len)))
	{
		key = s_dup(tmp);
	}
	else
	{
		key = s_n_dup(btw, len);
	}
	split = l_split(key, ";");
	put_lst_color(split);
	l_destroy(&split, x_del);
	s_del(&key);
}

void				put_escapes(char *s, char *start, char *end,
	void (*escape)(char *between, int len))
{
	char			*l;
	char			*r;
	int				i;
	int				start_len;

	i = 0;
	l = s_inner(s, start);
	(r = s_inner(s, end));
	if (!l || !r)
	{
		ps(s);
		return ;
	}
	while (&s[i] != l)
		pc(s[i++]);
	start_len = s_len(start);
	i = start_len;
	while (&l[i] != &r[0])
		i++;
	escape(&l[start_len], i - 1);
	return (put_escapes(&r[s_len(end)], start, end, escape));
}

int					pf_color(t_formatter **f, const char *s, int n)
{
	char			*tmp;

	(void)f;
	tmp = s_n_dup(s, n);
	put_escapes(tmp, "{", "}", escape_code_put);
	s_del(&tmp);
	return (n);
}
