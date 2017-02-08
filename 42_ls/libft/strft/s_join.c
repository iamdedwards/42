/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_join.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:54 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:06 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_padl(char *s1, char c, int len)
{
	char			*pad;

	pad = init_val(c, len);
	return (s_join(pad, s1));
}

char			*s_padr(char *s1, char c, int len)
{
	return (s_join(s1, init_val(c, len)));
}

char			*s_join(char const *s1, char const *s2)
{
	char			*joined;
	int				i;
	int				j;
	int				lengths;

	i = 0;
	j = 0;
	lengths = s_len(s1) + s_len(s2);
	if (!(joined = (char *)malloc(sizeof(char) * lengths + 1)))
		return (NULL);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	return (joined);
}
