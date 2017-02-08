/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 15:39:35 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			pf_outf_fd(t_formatter **f)
{
	return (sf_direct_proto(f, pf_fd_c_or_s, pf_fd_n));
}

static void			add_fd(t_list **l, void *arg)
{
	int			*fd_ref;
	int			fd;
	t_formatter	*f;

	f = (t_formatter *)(*l)->content;
	fd_ref = (int *)arg;
	fd = *fd_ref;
	f->fd = fd;
}

static int			pf_out_fd(t_formatter **f, const char *fs, int n)
{
	write((*f)->fd, fs, n);
	return (n);
}

int					ft_printf_fd(int fd, const char *format_string, ...)
{
	t_list		*f_list;
	va_list		args;
	int			nchars;

	va_start(args, format_string);
	if (!format_string)
		return (0);
	f_list = s_format_proto(format_string, &args);
	va_end(args);
	if (!f_list)
	{
		write(fd, format_string, s_len(format_string));
		return (s_len(format_string));
	}
	each_l_using(&f_list, add_fd, (void *)&fd);
	nchars = sf_iter(format_string, &f_list, pf_out_fd, pf_outf_fd);
	l_destroy(&f_list, x_del);
	return (nchars);
}
