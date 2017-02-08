/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:56 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:08 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_sub(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	int				i;

	i = 0;
	if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len && fresh)
	{
		fresh[i] = s[start];
		len--;
		i++;
		start++;
	}
	fresh[i] = '\0';
	return (fresh);
}
