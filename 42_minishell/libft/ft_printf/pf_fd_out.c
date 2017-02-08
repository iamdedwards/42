/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fd_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 16:26:14 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			pf_fd_padding(t_formatter **f, char c, int n)
{
	while (n--)
		write((*f)->fd, &c, 1);
}

static void			pf_fd_arg(t_formatter **f)
{
	pf_arg_proto(f, (*f)->fd);
}

static void			pf_fd_sign(t_formatter **f, char *s)
{
	write((*f)->fd, s, s_len(s));
}

int					pf_fd_c_or_s(t_formatter **f)
{
	int				ret;

	ret = sf_s_proto(f, pf_fd_padding, pf_fd_arg);
	return (ret);
}

int					pf_fd_n(t_formatter **f)
{
	int ret;

	ret = sf_n_proto(f, pf_fd_padding, pf_fd_sign, pf_fd_arg);
	return (ret);
}
