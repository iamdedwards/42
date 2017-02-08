/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mapi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:55 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:07 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_mapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapstr;

	i = 0;
	if ((mapstr = s_new(s_len(s))))
	{
		while (s[i])
		{
			mapstr[i] = f(i, s[i]);
			i++;
		}
		mapstr[i] = '\0';
	}
	return (mapstr);
}
