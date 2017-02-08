/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_direct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 20:14:48 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_s_s_map		*style_map(void)
{
	static t_s_s_map map[] = {
		{"b", "1"},
		{"fade", "2"},
		{"i", "3"},
		{"u", "4"},
		{"neg", "7"},
		{"blank", "8"},
		{"s", "9"},
		{"0", "0"},
		{0, 0},
	};

	return (map);
}

t_s_s_map		*color_map(void)
{
	static t_s_s_map map[] = {
		{"black", "0"},
		{"red", "1"},
		{"green", "2"},
		{"yellow", "3"},
		{"blue", "4"},
		{"magenta", "5"},
		{"cyan", "6"},
		{"white", "7"},
		{0, 0},
	};

	return (map);
}

char			pf_move_map(char *key)
{
	int					i;
	static t_s_c_map	map[] = {
		{"up", 'A'},
		{"down", 'B'},
		{"forward", 'C'},
		{"back", 'D'},
		{"up_ln", 'E'},
		{"down_ln", 'F'},
		{"column", 'G'},
		{"column_row", 'H'},
		{"erase", 'J'},
		{"clr", 'K'},
		{0, 0},
	};

	i = 0;
	while (map[i].key)
	{
		if (s_equals(key, map[i].key))
			return (map[i].value);
		i++;
	}
	return (0);
}
