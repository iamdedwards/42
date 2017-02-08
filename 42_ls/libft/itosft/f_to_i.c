/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_to_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:24:38 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 14:08:51 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					f_to_i(float n)
{
	int				ret;

	ret = (int)n;
	n = n - (int)n;
	n *= 10;
	if (n >= 5)
		ret++;
	return (ret);
}

char				*f_to_i_precise_work(char *fstr, int precise, int offset)
{
	int				start;
	int				up;

	if (!precise)
		return (fstr);
	start = s_len(fstr) - (1 + offset);
	up = c_is_digit(fstr[start]) && fstr[start] >= '5';
	while (start && (fstr[start] < '5'))
	{
		up = 1;
		start--;
	}
	if (up && (start >= 0 && fstr[start - 1] != '.'))
	{
		fstr[start - 1] += 1;
	}
	precise -= 1;
	return (f_to_i_precise_work(fstr, precise, ++offset));
}

int					f_to_i_precise(float n, int precise)
{
	char			*fstr;
	int				whole;
	char			*rest;

	fstr = f_to_s(n, precise);
	fstr = f_to_i_precise_work(fstr, precise, 0);
	whole = (s_to_i(fstr));
	rest = s_inner(fstr, ".");
	rest += 1;
	if (*rest >= '5')
		whole++;
	s_del(&fstr);
	return (whole);
}
