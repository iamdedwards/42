/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:05:33 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:07:03 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		pl_worker(t_list *elem, int index)
{
	ps(i_to_s(index));
	ps(". ");
	ps(elem->content);
}

void			p_lst(t_list *l)
{
	int				i;

	i = 1;
	while (l)
	{
		pl_worker(l, i);
		l = l->next;
		i++;
	}
}
