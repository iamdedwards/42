/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oo_map_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 15:53:11 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/05 15:57:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				oo_map_del(void **vmap)
{
	t_oo_map		*map;

	map = *vmap;
	x_del(&map->key);
	x_del(&map->value);
	x_del((void **)&map);
}
