/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_between.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:34 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:05 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*s_between(char *s, char *l, char *r)
{
	char			*left;
	char			*right;
	int				i;

	i = 0;
	left = s_inner(s, l);
	if (!left)
		return (NULL);
	right = s_inner(s, r);
	if (!right)
		return (NULL);
	while (&left[i] != right)
	{
		i++;
	}
	return (s_n_dup(&left[s_len(l)], i - 1));
}
