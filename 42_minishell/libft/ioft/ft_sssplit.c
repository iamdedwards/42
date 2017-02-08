/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:57:51 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/17 22:39:28 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_nsbtws(char *s, char *split)
{
	int		len;
	int		i;
	int		x;

	x = 0;
	i = 0;
	len = s_len(split);
	while (s[i])
	{
		i = s_nto_c(s, split[0]);
		if (s_n_cmp(&s[i], split, len) == 0)
		{
			x++;
			s += len + i;
			i = 0;
		}
	}
	return (x);
}

char	**ft_sssplit(char *s, char *split)
{
	char	**result;
	int		len;
	int		i;
	int		x;

	x = 0;
	i = 0;
	len = s_len(split);
	if (!(result = (char **)malloc(sizeof(char *) * ft_nsbtws(s, split) + 1)))
		return (NULL);
	while (s[i])
	{
		i = s_nto_c(s, split[0]);
		if (s_n_cmp(&s[i], split, len) == 0)
		{
			result[x] = (i) ? s_n_dup(s, i) : s_dup("\0");
			x++;
			s += len + i;
			i = 0;
		}
		result[x] = (!s[i]) ? s_n_dup(s, i) : result[x];
	}
	return (result);
}
