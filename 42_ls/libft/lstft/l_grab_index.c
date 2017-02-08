/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_grab_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:16 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_grab_index(t_list **head, size_t index)
{
	index = l_index_pos(*head, index);
	return (l_grab(head, index));
}
