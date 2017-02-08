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

char				*sf_get_wrap(int is_wrap, va_list *args)
{
	return ((is_wrap) ? va_arg(*args, char *) : "");
}

static void			sf_get_arg_sv(t_formatter **f_ref, va_list *args)
{
	char	*s;
	char	**sv;
	int		i;
	char	*after;

	i = 0;
	s = sf_get_wrap((*f_ref)->before, args);
	sv = va_arg(*args, char **);
	after = sf_get_wrap((*f_ref)->after, args);
	while (sv[i])
	{
		l_push_s(&(*f_ref)->l_arg_strs, sv_n_join((char *[]){
		s, sv[i++], after }, 3));
	}
}

static void			sf_get_arg_slst(t_formatter **f_ref, va_list *args)
{
	char	*s;
	t_list	*l;
	char	*after;

	s = sf_get_wrap((*f_ref)->before, args);
	l = ((t_list *)va_arg(*args, t_list *));
	after = sf_get_wrap((*f_ref)->after, args);
	while (l)
	{
		l_push_s(&(*f_ref)->l_arg_strs, (sv_n_join((char *[]){
		s, l->content, after}, 3)));
		l = l->next;
	}
}

void				sf_get_arg_s(t_formatter **f_ref, va_list *args)
{
	char		*tmp;

	if ((*f_ref)->vector)
		sf_get_arg_sv(f_ref, args);
	else if ((*f_ref)->list)
		sf_get_arg_slst(f_ref, args);
	else
	{
		tmp = va_arg(*args, char *);
		if ((int)tmp == 0)
			l_push_s(&(*f_ref)->l_arg_strs, (s_dup("(null)")));
		else
			l_push_s(&(*f_ref)->l_arg_strs, s_dup(tmp));
	}
}
