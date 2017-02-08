/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:12:44 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/29 23:30:33 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/s_format.h"

void				interpret(t_list **store, va_list *vargs, char *s, int n)
{
	(void)n;
	if (s[0] == 's')
	{
		l_push_s(store, s_dup(va_arg(*vargs, char *)));
	}
	if (s[0] == 'd')
	{
		l_push_s(store, i_to_s(va_arg(*vargs, int)));
	}
}

void				save_until(t_list **store, va_list *vargs, const char *s)
{
	char			*l;
	char			*r;
	int				i;

	i = 0;
	l = s_inner(s, "{");
	(r = s_inner(s, "}"));
	if (!l || !r)
	{
		l_push_s(store, s_dup(s));
		return ;
	}
	while (&s[i] != l)
		i++;
	l_push_s(store, s_n_dup(s, i));
	i = 1;
	while (&l[i] != &r[0])
		i++;
	interpret(store, vargs, &l[1], i - 1);
	return (save_until(store, vargs, &r[1]));
}

char				*s_format(const char *format, ...)
{
	va_list			vargs;
	t_list			*store;

	store = 0;
	va_start(vargs, format);
	save_until(&store, &vargs, format);
	va_end(vargs);
	return (lxx_to_s(&store));
}
