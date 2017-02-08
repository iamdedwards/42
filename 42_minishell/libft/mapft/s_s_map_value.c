/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_s_map_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 20:28:04 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 20:28:41 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_s_map_value(t_s_s_map *map, char *key)
{
	int				i;

	i = 0;
	while (map[i].key)
	{
		if (s_equals(map[i].key, key))
		{
			return (map[i].value);
		}
		i++;
	}
	return (0);
}
