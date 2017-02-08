/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_equals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:53 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:06 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				s_equals(char *s1, char *s2)
{
	size_t i;

	i = 0;
	if (!s1[0] && !s2[0])
		return (1);
	if (!s1[0] || !s2[0])
		return (0);
	if (s_cmp(s1, s2) == 0)
		return (1);
	if (s_len(s1) != s_len(s2))
		return (0);
	while (s1[i])
	{
		if (s1[i] > s2[i])
			return (0);
		if (s1[i] < s2[i])
			return (0);
		i++;
	}
	return (1);
}

int				c_equals(char a, char b)
{
	return (a == b);
}
