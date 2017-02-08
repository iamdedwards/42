/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oo_map_getval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:50:21 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/05 15:53:57 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*oo_map_getval(t_oo_map *map,
		void *try_get, int (*oo_map_val_getter)(void *, void *))
{
	if (oo_map_val_getter(map->key, try_get))
		return (map->value);
	return (NULL);
}
