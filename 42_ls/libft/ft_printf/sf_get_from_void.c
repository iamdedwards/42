/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_get_from_void.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 17:30:34 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			sf_get_arg_from_voidl(t_formatter **f_ref, va_list *args)
{
	t_list		*lst;
	char		*before;
	char		*after;
	char		*tmp;
	t_stringer	stringer;

	before = sf_get_wrap((*f_ref)->before, args);
	lst = va_arg(*args, t_list *);
	stringer = va_arg(*args, t_stringer);
	after = sf_get_wrap((*f_ref)->after, args);
	while (lst)
	{
		tmp = stringer(lst->content);
		l_push_s(&(*f_ref)->l_arg_strs,
		sv_n_join((char *[]){before, tmp, after}, 3));
		lst = lst->next;
	}
}

void				sf_get_arg_from_void(t_formatter **f_ref, va_list *args)
{
	void		*ptr;
	char		*before;
	char		*after;
	char		*tmp;
	t_stringer	stringer;

	if ((*f_ref)->list)
		return (sf_get_arg_from_voidl(f_ref, args));
	before = sf_get_wrap((*f_ref)->before, args);
	ptr = va_arg(*args, void *);
	stringer = va_arg(*args, t_stringer);
	after = sf_get_wrap((*f_ref)->after, args);
	tmp = stringer(ptr);
	l_push_s(&(*f_ref)->l_arg_strs,
	sv_n_join((char *[]){before, tmp, after}, 3));
}
