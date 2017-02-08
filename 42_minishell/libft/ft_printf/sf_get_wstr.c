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

static void			sf_get_arg_wsv(t_formatter **f_ref, va_list *args)
{
	char	*s;
	wchar_t	**sv;
	int		i;
	char	*after;
	char	*tmp;

	i = 0;
	s = sf_get_wrap((*f_ref)->before, args);
	sv = va_arg(*args, wchar_t **);
	after = sf_get_wrap((*f_ref)->after, args);
	while (sv[i])
	{
		tmp = ws_to_s(sv[i]);
		l_push_s(&(*f_ref)->l_arg_strs, sv_n_join((char *[]){
		s, tmp, after }, 3));
		s_del(&tmp);
	}
}

static void			sf_get_arg_wslst(t_formatter **f_ref, va_list *args)
{
	char	*s;
	t_list	*l;
	char	*after;
	char	*tmp;

	s = sf_get_wrap((*f_ref)->before, args);
	l = ((t_list *)va_arg(*args, t_list *));
	after = sf_get_wrap((*f_ref)->after, args);
	while (l)
	{
		tmp = ws_to_s(l->content);
		l_push_s(&(*f_ref)->l_arg_strs, s_dup(sv_n_join((char *[]){
		s, tmp, after}, 3)));
		l = l->next;
		s_del(&tmp);
	}
}

void				sf_get_arg_ws(t_formatter **f_ref, va_list *args)
{
	int			i;
	wchar_t		*wtmp;
	char		*tmp;

	i = 0;
	if ((*f_ref)->vector)
	{
		sf_get_arg_wsv(f_ref, args);
	}
	else if ((*f_ref)->list)
	{
		sf_get_arg_wslst(f_ref, args);
	}
	else
	{
		wtmp = (va_arg(*args, wchar_t *));
		if (!wtmp)
			tmp = s_dup("(null)");
		else
			tmp = ws_to_s(wtmp);
		l_push_s(&(*f_ref)->l_arg_strs, (tmp));
	}
}
