/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oo_new_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 11:33:11 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/26 11:40:40 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_oo_map		*new_map(void *elem1, void *elem2)
{
	t_oo_map *map;

	map = (t_oo_map *)malloc(sizeof(map));
	map->key = elem1;
	map->value = elem2;
	return (map);
}
