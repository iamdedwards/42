/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_principal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 17:32:27 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:50 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printf(const char *format_string, ...)
{
	t_list		*f_list;
	va_list		args;
	int			nchars;

	va_start(args, format_string);
	if (!format_string)
		return (0);
	f_list = s_format_proto(format_string, &args);
	va_end(args);
	if (!f_list)
	{
		put_escapes((char *)format_string, "{", "}", escape_code_put);
		return (s_len(format_string));
	}
	nchars = sf_iter(format_string, &f_list, pf_color, pf_direct);
	l_destroy(&f_list, x_del);
	return (nchars);
}
