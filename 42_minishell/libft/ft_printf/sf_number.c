/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:40:21 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sf_n_arg_len(t_formatter *f)
{
	if (f->arg_str[0] == '-')
	{
		return (s_len(f->arg_str) - 1);
	}
	else
	{
		return (s_len(f->arg_str));
	}
}

int			sf_n_proto(t_formatter **f,
void (*out_padding)(t_formatter **f, char c, int n),
void (*out_sign)(t_formatter **f, char *s),
void (*out_arg)(t_formatter **f))
{
	int	space_pad;
	int	zero_pad;
	int	sign_width;

	sf_s_list_numbers(f, out_padding);
	sf_n_set(*f, &space_pad, &zero_pad);
	if ((*f)->pad_right)
	{
		sign_width = pf_n_sign(f, out_sign);
		out_padding(f, '0', zero_pad);
		out_arg(f);
		out_padding(f, ' ', space_pad);
	}
	else
	{
		out_padding(f, ' ', space_pad);
		sign_width = pf_n_sign(f, out_sign);
		out_padding(f, '0', zero_pad);
		out_arg(f);
	}
	return (sign_width + sf_n_arg_len((*f)) + space_pad + zero_pad);
}

int			pf_n(t_formatter **f)
{
	int ret;

	ret = sf_n_proto(f, pf_padding, pf_sign, pf_arg);
	return (ret);
}

int			sf_n(t_formatter **f)
{
	int ret;

	ret = sf_n_proto(f, sf_save_padding, sf_save_sign, sf_save_arg);
	return (ret);
}
