/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_n_equals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:55 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/13 20:15:30 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				s_n_equals(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1[0] && !s2[0])
		return (1);
	if (n == 0)
		return (1);
	if (!s1[0] || !s2[0])
		return (0);
	while (s1[i] && n--)
	{
		if ((s1[i]) > (s2[i]))
			return (0);
		if ((s1[i]) < (s2[i]))
			return (0);
		i++;
	}
	return (1);
}
