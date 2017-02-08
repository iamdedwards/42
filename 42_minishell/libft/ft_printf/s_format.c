/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 15:33:06 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/01 16:52:00 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	l_to_s_len(t_list *f_list)
{
	int		i;
	t_list	*l;

	i = 0;
	while (f_list)
	{
		l = as_formatter(f_list)->l_formatted;
		while (l)
		{
			i += s_len(l->content);
			l = l->next;
		}
		if (!l)
		{
			f_list = f_list->next;
		}
	}
	return (i);
}

static char	*sfl_to_s(t_list *f_list)
{
	char	*ret;
	int		len;
	int		i;
	t_list	*l;
	t_list	*l_run;

	len = l_to_s_len(f_list);
	ret = s_new(len);
	i = 0;
	while (f_list)
	{
		l = as_formatter(f_list)->l_formatted;
		l_run = l;
		while (l_run)
		{
			s_cpy(&ret[s_len(ret)], l_run->content);
			l_run = l_run->next;
		}
		if (!l_run)
		{
			l_destroy(&l, l_destroy_content);
			f_list = f_list->next;
		}
	}
	return (ret);
}

char		*rubbish_format(const char *format_string, ...)
{
	t_list		*f_list;
	t_formatter	*f;
	va_list		args;
	char		*ret;

	va_start(args, format_string);
	f_list = s_format_proto(format_string, &args);
	va_end(args);
	if (!f_list)
	{
		return (s_dup(format_string));
	}
	(void)sf_iter(format_string, &f_list, sf_save_unformatted, sf_direct);
	f = as_formatter(f_list);
	ret = sfl_to_s(f_list);
	return (ret);
}
