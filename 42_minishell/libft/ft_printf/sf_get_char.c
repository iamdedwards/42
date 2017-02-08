/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:54:03 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			sf_get_arg_charv(t_formatter **f_ref, va_list *args)
{
	char			*before;
	char			*after;
	char			*c;
	int				i;
	char			*tmp;

	i = 0;
	before = sf_get_wrap((*f_ref)->before, args);
	c = va_arg(*args, char *);
	after = sf_get_wrap((*f_ref)->after, args);
	if (!c)
	{
		l_push_s(&(*f_ref)->l_arg_strs,
		sv_n_join((char *[]){before, after, 0}, 2));
	}
	while (c && c[i])
	{
		tmp = c_to_s(c[i]);
		l_push_s(&(*f_ref)->l_arg_strs, sv_n_join((char *[])
		{before, tmp, after}, 3));
		s_del(&tmp);
		i++;
	}
}

void				sf_get_arg_char(t_formatter **f_ref, va_list *args)
{
	if ((*f_ref)->vector)
		sf_get_arg_charv(f_ref, args);
	else
		l_push_s(&(*f_ref)->l_arg_strs, c_to_s(va_arg(*args, int)));
}
