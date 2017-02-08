/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:42:37 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			sf_get_arg_set_var(t_str_section_to_int *tssti,
		va_list *args)
{
	int				value;
	va_list			args_copy;

	if ((*tssti).limits.start != -'*')
	{
		return (0);
	}
	va_copy(args_copy, *args);
	value = va_arg(args_copy, int);
	if (SF_SAFE && value > (short)MAXOF(short))
	{
		TIX(value);
		exit(42);
	}
	va_end(args_copy);
	(*tssti).value = va_arg(*args, int);
	return (1);
}

static t_varg_func	sf_get_getter(char key)
{
	static t_varg_func_map	map[] = {
		{"s", sf_get_arg_s},
		{"S", sf_get_arg_ws},
		{"c", sf_get_arg_char},
		{"C", sf_get_arg_wchar},
		{"f", sf_get_arg_float},
		{"uUiIdDxXoObB", sf_get_num},
		{"pP", sf_get_arg_pointer},
		{">", sf_get_arg_from_void},
		{0, 0}};
	int						i;

	i = 0;
	while (map[i].keys)
	{
		if (s_haschar(map[i].keys, key))
			return (map[i].getter);
		i++;
	}
	return (NULL);
}

int					sf_get_arg(t_formatter **f_ref, va_list *args)
{
	t_varg_func		getter;
	char			type;

	type = (*f_ref)->type.value | ' ';
	sf_get_arg_set_var(&(*f_ref)->width, args);
	sf_get_arg_set_var(&(*f_ref)->precision, args);
	getter = sf_get_getter((*f_ref)->type.value);
	if (getter)
		getter(f_ref, args);
	else if ('%' == (*f_ref)->type.value)
	{
		(*f_ref)->raw = &(*f_ref)->raw[-1];
		l_push_s(&(*f_ref)->l_arg_strs, s_dup("%"));
	}
	if ((*f_ref)->type.value == 'x' || (*f_ref)->type.value == 'p')
	{
		l_s_iter(&(*f_ref)->l_arg_strs, c_to_lower);
	}
	return (getter != NULL || (*f_ref)->type.value == '%');
}
