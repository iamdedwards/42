/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width_and_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 12:01:06 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:50 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	interface_sf_get_arg(t_list **vlst_ref, void *args_ref)
{
	t_formatter	*f;

	f = as_formatter(*vlst_ref);
	sf_get_arg(&f, (va_list *)args_ref);
}

t_list		*s_format_proto(const char *format_string, va_list *args)
{
	t_list		*s_formats;
	t_list		*s_format_elem;
	int			parse_start_pos;

	s_formats = NULL;
	parse_start_pos = 0;
	while ((s_format_elem = sf_get_formats(format_string, &parse_start_pos)))
	{
		l_push(&s_formats, s_format_elem);
	}
	if (s_formats != NULL)
	{
		each_l(&s_formats, populate_formatter);
		each_l_using(&s_formats, interface_sf_get_arg, args);
	}
	return (s_formats);
}
