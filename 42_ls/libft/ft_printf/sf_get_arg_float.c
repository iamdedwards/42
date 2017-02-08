/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_get_arg_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 20:42:28 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			sf_get_arg_floatlst(t_formatter **f_ref, va_list *args)
{
	t_list	*lst;
	char	*before;
	char	*after;
	char	*tmp;
	int		precision_value;

	before = sf_get_wrap((*f_ref)->before, args);
	lst = va_arg(*args, t_list *);
	after = sf_get_wrap((*f_ref)->after, args);
	precision_value = ((*f_ref)->precision.value >= 0) ?
	(*f_ref)->precision.value : 6;
	while (lst)
	{
		tmp = f_to_s(*((float *)lst->content), precision_value);
		l_push_s(&(*f_ref)->l_arg_strs, sv_n_join((char *[]){
		before, tmp, after}, 3));
		s_del(&tmp);
		lst = lst->next;
	}
}

void			sf_get_arg_float(t_formatter **f_ref, va_list *args)
{
	float		fl;

	if ((*f_ref)->list)
	{
		sf_get_arg_floatlst(f_ref, args);
	}
	else
	{
		fl = va_arg(*args, double);
		if ((*f_ref)->precision.value != -1)
		{
			l_push_s(&(*f_ref)->l_arg_strs,
			f_to_s(fl, (*f_ref)->precision.value));
		}
		else
		{
			l_push_s(&(*f_ref)->l_arg_strs, f_to_s(fl, 6));
		}
	}
}
