/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_get_arg_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 20:00:09 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			sf_get_arg_pointer(t_formatter **f_ref, va_list *args)
{
	long		ll;
	t_list		*lst;

	if ((*f_ref)->list)
	{
		lst = va_arg(*args, t_list *);
		while (lst)
		{
			l_push_s(&(*f_ref)->l_arg_strs,
			ll_to_s_base((long)lst->content, 16));
			lst = lst->next;
		}
	}
	else
	{
		ll = (long)va_arg(*args, void *);
		l_push_s(&(*f_ref)->l_arg_strs, ll_to_s_base(ll, 16));
	}
	(*f_ref)->hash = 1;
}
