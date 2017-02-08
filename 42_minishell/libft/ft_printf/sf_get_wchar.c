/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_vargs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 23:30:14 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				sf_get_arg_wvchar(t_formatter **f_ref, va_list *args)
{
	char			*before;
	char			*after;
	wchar_t			*c;
	int				i;
	char			*tmp;

	i = 0;
	before = sf_get_wrap((*f_ref)->before, args);
	if ((*f_ref)->vector)
	{
		c = va_arg(*args, wchar_t *);
		after = sf_get_wrap((*f_ref)->after, args);
		while (c[i])
		{
			tmp = unicode_to_utf8(c[i]);
			l_push_s(&(*f_ref)->l_arg_strs, sv_n_join((char *[])
			{before, tmp, after}, 3));
			s_del(&tmp);
			i++;
		}
	}
}

void				sf_get_arg_wchar(t_formatter **f_ref, va_list *args)
{
	wchar_t			c;
	int				i;

	i = 0;
	if ((*f_ref)->vector)
	{
		sf_get_arg_wvchar(f_ref, args);
	}
	else
	{
		c = va_arg(*args, wchar_t);
		l_push_s(&(*f_ref)->l_arg_strs, (!c) ? s_dup("") :
		unicode_to_utf8(c));
	}
}
