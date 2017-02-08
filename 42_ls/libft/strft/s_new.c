/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:56 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 17:23:11 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			s_set(char **current, char *newval)
{
	if (current && *current)
		x_del((void **)current);
	*current = newval;
}

char			*s_init(int val, size_t size)
{
	char			*s;

	s = s_new(size);
	s = s_n_cpy(s, init_val(val, size), size);
	return (s);
}

char			*s_new(size_t size)
{
	return (init_val('\0', size + 1));
}
