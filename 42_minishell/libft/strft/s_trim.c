/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_trim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:57 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:08 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_trim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] != ' ' && s[k] != '\n' && s[k] != '\t')
		{
			k++;
			j = k;
		}
		else
			k++;
	}
	if (j == 0)
		return (s_dup(""));
	return (s_sub(s, i, j - i));
}
