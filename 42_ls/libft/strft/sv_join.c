/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:19:01 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 17:23:25 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				sv_n_len(char **s_ref, size_t n)
{
	int				len;
	int				i;

	len = 0;
	i = 0;
	while (n--)
	{
		if (s_ref[i])
			len += s_len(s_ref[i]);
		i++;
	}
	return (len);
}

int				sv_len(char **s_ref)
{
	int				len;
	int				i;

	len = 0;
	i = 0;
	while (s_ref[i])
	{
		if (s_ref[i])
			len += s_len(s_ref[i]);
		i++;
	}
	return (len);
}

char			*sv_n_join(char **s_ref, size_t n)
{
	char			*s;
	size_t			i;

	i = 0;
	s = s_new(sv_n_len(s_ref, n));
	while (i < n)
	{
		s_cpy(&s[s_len(s)], s_ref[i]);
		i++;
	}
	return (s);
}

char			*sv_join(char **s_ref)
{
	char			*s;
	int				i;

	i = 0;
	s = s_new(sv_len(s_ref));
	while (s_ref[i])
	{
		if (s_ref[i])
			s_cpy(&s[s_len(s)], s_ref[i]);
		i++;
	}
	return (s);
}
