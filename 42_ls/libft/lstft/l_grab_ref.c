/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_grab_ref.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:16 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_grab_ref(t_list **head, t_list **elem)
{
	int				index;

	index = l_refindex(head, elem);
	return (l_grab(head, index));
}
