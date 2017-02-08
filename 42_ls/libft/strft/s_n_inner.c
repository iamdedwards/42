/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_n_inner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:56 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:07 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_n_inner(const char *str, const char *substr, size_t n)
{
	size_t size;
	size_t j;

	j = 0;
	if (!n)
		return (NULL);
	if (!*str)
		return (NULL);
	if (!*substr)
		return ((char *)str);
	size = s_len(substr);
	while ((*str && s_len(str) >= size) && j < n)
	{
		if (s_n_cmp(str, substr, size) == 0)
			return ((char *)str);
		str = str + 1;
		j++;
	}
	return (NULL);
}
