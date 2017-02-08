/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_has.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 12:24:22 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/28 15:19:21 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					s_has_other_than(char *s, char *ok)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if (!s_haschar(ok, s[i]))
			return (1);
		i++;
	}
	return (0);
}

int					s_has(char *s, int (*f)(int))
{
	while (*s)
	{
		if (f(*s))
			return (*s);
		(void)*s++;
	}
	return (0);
}

int					s_hasi(char *s, int (*f)(int))
{
	int				i;

	i = 0;
	while (s[i])
	{
		if (f(s[i]))
			return (i);
		i++;
	}
	return (-1);
}
