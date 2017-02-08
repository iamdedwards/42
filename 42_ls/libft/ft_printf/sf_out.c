/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 15:30:20 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			pf_padding(t_formatter **f, char c, int n)
{
	(void)f;
	if (n)
	{
		pc_repeat(c, n);
	}
}

void			pf_arg_proto(t_formatter **f, int fd)
{
	int				precise;
	int				numeric;
	int				print_nothing;
	char			type;

	type = (*f)->type.value | ' ';
	if ((0 == (*f)->arg_str[0] && type == 'c') ||
	(0 == (*f)->precision.value && type == 'c'))
	{
		pc('\0');
		return ;
	}
	numeric = s_haschar("dfiuox", type);
	precise = type == 's' && (*f)->precision.value != -1;
	print_nothing = (type == 'x' || type == 'o') && (!(*f)->precision.value);
	if (precise)
		ps_n_fd((char *)((*f)->arg_str), fd, (*f)->precision.value);
	else if (!print_nothing)
	{
		if (numeric && (*f)->arg_str[0] == '-')
			ps_fd(&(*f)->arg_str[1], fd);
		else
			ps_fd((*f)->arg_str, fd);
	}
}

void			pf_arg(t_formatter **f)
{
	pf_arg_proto(f, 1);
}

void			pf_sign(t_formatter **f, char *s)
{
	(void)f;
	ps(s);
}
