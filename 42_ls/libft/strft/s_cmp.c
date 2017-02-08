/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cmp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:50 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:05 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				s_cmp(const char *s1, const char *s2)
{
	int				i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((unsigned char)s2[0]);
	if (!s2)
		return ((unsigned char)s1[0]);
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
