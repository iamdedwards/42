/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_grab_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:16 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_grab_type(t_list **head, size_t type)
{
	int				index;

	index = l_type_index(*head, type);
	return (l_grab(head, index));
}
