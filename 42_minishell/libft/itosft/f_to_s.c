/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 12:50:47 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/25 17:12:52 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		float_tos_adjust(t_list **floaty_ref, int offset)
{
	t_list			*floaty;
	t_list			*end_digit;
	char			*digit_as_str;
	char			*tmp;

	floaty = *floaty_ref;
	end_digit = l_goto(floaty, -1 - offset);
	digit_as_str = end_digit->content;
	if (digit_as_str[0] == '.')
		return ;
	if (digit_as_str[0] == '9')
	{
		digit_as_str[0] = '0';
		offset += 1;
		return (float_tos_adjust(floaty_ref, offset));
	}
	else
	{
		tmp = i_to_s(s_to_i(end_digit->content) + 1);
		digit_as_str[0] = tmp[0];
		s_del(&tmp);
	}
}

char			*f_to_s(float n, unsigned int limit)
{
	t_list			*floaty;
	char			*woohoo;

	floaty = NULL;
	l_push_s(&floaty, i_to_s(n));
	l_push_s(&floaty, s_dup("."));
	n = n - (int)n;
	while (limit-- > 0)
	{
		n *= 10;
		l_push_s(&floaty, i_to_s((int)n));
		n = n - (float)((int)n);
	}
	if (n * 10 >= 5)
	{
		float_tos_adjust(&floaty, 0);
	}
	woohoo = lxx_to_s(&floaty);
	return (woohoo);
}
