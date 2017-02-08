/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_inner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:54 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:06 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_inner(const char *str, const char *substr)
{
	size_t size;

	if (*substr == '\0')
		return ((char *)str);
	size = s_len(substr);
	while (*str && s_len(str) >= size)
	{
		if (s_n_cmp(str, substr, size) == 0)
			return ((char *)str);
		str = str + 1;
	}
	return (NULL);
}
