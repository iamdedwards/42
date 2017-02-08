/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:29:00 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:50 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sf_arg_len(t_formatter *f)
{
	int ret;

	if (c_to_lower(f->type.value) == 'c' || (f->type.value == '%'))
	{
		return (s_len(f->arg_str));
	}
	ret = (f->precision.value != -1 && f->precision.value <
	(int)s_len(f->arg_str)) ?
	f->precision.value : s_len(f->arg_str);
	return (ret);
}

void			sf_s_list_numbers(t_formatter **f_ref,
void (*out)(t_formatter **, char, int))
{
	static	int			lst_num = 1;
	static	t_formatter	*f_memory = NULL;
	char				*line_num;
	int					i;

	if (c_to_lower((*f_ref)->type.value) == 'x')
		return ;
	i = 0;
	if (*f_ref != f_memory)
	{
		f_memory = *f_ref;
		lst_num = 1;
	}
	if (((*f_ref)->vector || (*f_ref)->list) && (*f_ref)->hash)
	{
		line_num = i_to_s(lst_num);
		out(f_ref, '(', 1);
		while (line_num[i])
		{
			out(f_ref, line_num[i++], 1);
		}
		out(f_ref, ')', 1);
		lst_num++;
		s_del(&line_num);
	}
}

static int		get_padding_len(t_formatter *f)
{
	int		output;
	int		padding;

	output = sf_arg_len(f);
	padding = 0;
	if (output < (f)->width.value)
	{
		padding = ((f)->width.value - output) - ((f->type.value == 'c' &&
		!(f)->arg_str[0]) || (f->type.value == 'c' && !(f)->precision.value));
	}
	return (padding);
}

int				sf_s_proto(t_formatter **f,
void (*out_padding)(t_formatter **, char, int),
void (*out_arg)(t_formatter **))
{
	int		padding;
	int		ret;

	padding = (SF_LINUX && (*f)->type.value == '%');
	sf_s_list_numbers(f, out_padding);
	padding = get_padding_len(*f);
	if ((*f)->pad_right)
	{
		out_arg(f);
		out_padding(f, ' ', padding);
	}
	else
	{
		out_padding(f, ' ', padding);
		out_arg(f);
	}
	if ((ret = (((*f)->list || (*f)->vector) && (*f)->space)))
		out_padding(f, ' ', 1);
	return (ret + (sf_arg_len(*f) + padding) +
			((*f)->type.value == 'c' && !(*f)->arg_str[0]));
}
