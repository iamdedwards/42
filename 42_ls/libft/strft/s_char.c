/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:40 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:05 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_char(const char *str, int c)
{
	int				i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == 0 && c == 0)
		return ((char *)&str[i]);
	else
		return (NULL);
}
