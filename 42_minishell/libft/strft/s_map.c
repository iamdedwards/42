/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:55 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/28 14:21:37 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_filter(char *s, int (*f)(int))
{
	unsigned int	i;
	unsigned int	j;
	char			*mapstr;

	i = 0;
	j = 0;
	mapstr = s_new(s_len(s));
	while (s[i])
	{
		if (f(s[i]))
		{
			mapstr[j] = s[i];
			j++;
		}
		i++;
	}
	mapstr[i] = '\0';
	return (mapstr);
}

char			*s_map(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*mapstr;

	i = 0;
	if ((mapstr = s_new(s_len(s))))
	{
		while (s[i])
		{
			mapstr[i] = f(s[i]);
			i++;
		}
		mapstr[i] = '\0';
	}
	return (mapstr);
}
