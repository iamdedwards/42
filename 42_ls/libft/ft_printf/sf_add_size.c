/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_add_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 11:53:11 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			sf_size_map(char *str)
{
	int					index;
	static	t_s_i_map	map[] = {
		{ "hh", SF_CHAR },
		{ "h", SF_SHORT },
		{ "l", SF_LONG },
		{ "z", SF_SIZET },
		{ "ll", SF_LONGLONG },
		{ "j", SF_INTMAXT },
		{0, 0}
	};

	index = 0;
	while (map[index].key)
	{
		if (s_equals(map[index].key, str))
		{
			return (map[index].value);
		}
		index++;
	}
	return (SF_SIZELESS);
}

static int			sf_size_key_parse(t_formatter **f,
	t_str_section_to_int *init_section)
{
	char			key[3];
	int				x;
	int				y;

	x = (*init_section).limits.start;
	y = (*init_section).limits.end;
	buff_val(key, 0, 3);
	if (y - x > 1)
	{
		key[0] = (*f)->raw[x];
		key[1] = (*f)->raw[x + 1];
	}
	else
	{
		key[0] = (*f)->raw[x];
	}
	(*init_section).value = sf_size_map(key);
	return (1);
}

void				add_size(t_formatter **f, t_str_section_to_int s)
{
	(*f)->size = s;
	sf_size_key_parse(f, &(*f)->size);
}
