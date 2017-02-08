/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width_and_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 12:01:06 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sf_parse_int(t_formatter **f,
		t_str_section_to_int *init_section)
{
	int				x;
	int				y;

	x = (*init_section).limits.start;
	y = (*init_section).limits.end;
	(*init_section).value = (s_n_to_ui(&(*f)->raw[x], y - x));
	return (1);
}

void			add_precision(t_formatter **f, t_str_section_to_int s)
{
	(*f)->precision = s;
	if ((*f)->raw[(*f)->precision.limits.start] == '.')
	{
		(*f)->precision.value = 0;
	}
	else if ((*f)->raw[(*f)->precision.limits.start] == '*')
	{
		(*f)->precision.limits.start = -'*';
		(*f)->precision.limits.end = -'*';
	}
	else
	{
		sf_parse_int(f, &(*f)->precision);
	}
}

void			add_min_width(t_formatter **f, t_str_section_to_int s)
{
	(*f)->width = s;
	if ((*f)->raw[(*f)->width.limits.start] == '*')
	{
		(*f)->width.limits.start = -'*';
		(*f)->width.limits.end = -'*';
	}
	else
		sf_parse_int(f, &(*f)->width);
}

void			add_type(t_formatter **f, t_str_section_to_int s)
{
	(*f)->type = s;
	(*f)->type.value = (*f)->raw[s.limits.start];
	if (!s_haschar("XO", (*f)->type.value) && c_is_upper((*f)->type.value))
	{
		((*f)->size.value = SF_LONGLONG);
	}
}
