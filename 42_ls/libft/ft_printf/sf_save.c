/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_direct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 20:14:48 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:50 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			sf_save_padding(t_formatter **f, char c, int n)
{
	if (n)
	{
		l_push(&(*f)->l_formatted, l_new_s(s_init(c, n)));
	}
}

void			sf_save_arg(t_formatter **f)
{
	char			*push;
	int				precise;
	int				numeric;
	char			type;

	if (0 == (*f)->arg_str[0])
		return ;
	type = (*f)->type.value | ' ';
	push = NULL;
	numeric = (type == 'd' || type == 'f') || (type == 'i' || type == 'u');
	precise = type == 's' && (*f)->precision.value != -1;
	if (precise)
		push = s_n_dup((char *)((*f)->arg_str), (*f)->precision.value);
	if (numeric && (*f)->arg_str[0] == '-')
		push = s_dup(&(*f)->arg_str[1]);
	else
		push = s_dup((*f)->arg_str);
	if (push)
		l_push_s(&(*f)->l_formatted, push);
}

void			sf_save_sign(t_formatter **f, char *s)
{
	l_push(&(*f)->l_formatted, l_new_s(s_dup(s)));
}

int				sf_save_unformatted(t_formatter **f, const char *s, int n)
{
	if (n)
	{
		l_push(&(*f)->l_formatted, l_new_s((s_n_dup(s, n))));
	}
	return (n);
}
