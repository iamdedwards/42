/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_get_formats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 10:32:27 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/12 13:51:39 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_formatter		*t_formatter_new(void)
{
	t_formatter			*f;

	f = (t_formatter *)malloc(sizeof(t_formatter));
	f->precision = (t_str_section_to_int){{-1, -1}, 0};
	f->width = (t_str_section_to_int){{-1, -1}, 0};
	f->size = (t_str_section_to_int){{-1, -1}, 0};
	f->type = (t_str_section_to_int){{-1, -1}, 0};
	f->pad_right = 0;
	f->zero = 0;
	f->plus = 0;
	f->hash = 0;
	f->list = 0;
	f->vector = 0;
	f->raw = 0;
	f->parser_position = 0;
	f->space = 0;
	f->arg_str = 0;
	f->before = 0;
	f->after = 0;
	f->l_arg_strs = 0;
	f->l_formatted = 0;
	return (f);
}

static	t_list			*sf_add_formatter(t_list *x, t_formatter *f)
{
	f = sf_init_formatter(f, x->content);
	x->content = f;
	return (x);
}

t_list					*sf_get_formats(const char *format_string,
		int *start_p_ref)
{
	t_list			*s_formats;
	int				untill;
	int				start_pos;
	char			*check_format;

	s_formats = NULL;
	start_pos = *start_p_ref;
	if (start_pos >= (int)s_len(format_string))
		return (NULL);
	check_format = s_inner(&format_string[start_pos], "%");
	if (!check_format || ((check_format[0] == '%') && !check_format[1]))
		return (NULL);
	untill = s_nto_c(&format_string[start_pos], '%') + 1;
	if (format_string[start_pos + untill])
		s_formats = l_new_s((char *)&format_string[start_pos + untill]);
	s_formats = sf_add_formatter(s_formats, t_formatter_new());
	*start_p_ref = start_pos + untill;
	*start_p_ref += (format_string[*start_p_ref] == '%');
	return (s_formats);
}
