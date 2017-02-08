/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_clr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:45 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 17:22:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_swap(char **current, char *new)
{
	x_del((void**)current);
	*current = new;
	return (new);
}

char			*s_n_clr(char *s, size_t start)
{
	size_t size;

	if (start >= s_len(s))
		return (s);
	size = s_len(s);
	while (size--)
	{
		s[start] = 0;
		start++;
	}
	return (s);
}
