/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_decide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:34:26 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sf_c_or_s(t_formatter **f)
{
	return (sf_s_proto(f, sf_save_padding, sf_save_arg));
}

static int	pf_c_or_s(t_formatter **f)
{
	int				ret;

	ret = sf_s_proto(f, pf_padding, pf_arg);
	return (ret);
}

int			sf_direct_proto(t_formatter **f_ref,
			int (*c_or_s_func)(t_formatter **),
			int (*n_func)(t_formatter **))
{
	int				ret;
	t_list			*runner;
	char			c;

	c = ((*f_ref)->type.value == '%') ?
	((*f_ref)->type.value) | ' ' :
	(*f_ref)->type.value;
	ret = 0;
	runner = (*f_ref)->l_arg_strs;
	while (runner)
	{
		(*f_ref)->arg_str = runner->content;
		if ((c == 's' || c == 'c') || c == '%')
		{
			ret += c_or_s_func(f_ref);
		}
		else
		{
			ret += n_func(f_ref);
		}
		runner = runner->next;
	}
	return (ret);
}

int			pf_direct(t_formatter **f_ref)
{
	t_list	*wtf;
	int		ret;

	wtf = (*f_ref)->l_arg_strs;
	ret = (sf_direct_proto(f_ref, pf_c_or_s, pf_n));
	l_destroy(&wtf, x_del);
	return (ret);
}

int			sf_direct(t_formatter **f_ref)
{
	int				ret;

	ret = (sf_direct_proto(f_ref, sf_c_or_s, sf_n));
	return (ret);
}
