/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_n_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:24:02 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sf_n_zero_pad_calc(t_formatter *f, int curr_width)
{
	int		zeroes;
	int		hexa_sign;
	char	type;

	type = (f)->type.value | ' ';
	zeroes = 0;
	hexa_sign = ((type == 'x') && (f)->hash) * 2;
	if (f->precision.value > curr_width)
	{
		zeroes = (f->precision.value - curr_width);
	}
	else if ((f->precision.value != -1 && f->zero) && (type != 'x' && f->hash))
	{
		if (curr_width < f->precision.value)
			return (f->precision.value - hexa_sign);
	}
	else if ((f->width.value != -1 && (f->zero)) && (!f->pad_right))
	{
		zeroes = (f->width.value - curr_width);
	}
	if ((zeroes && (f)->width.value) && (f)->precision.value == -1)
		zeroes -= pf_n_sign(&f, 0);
	return (zeroes);
}

static int	sf_will_print_nothing(t_formatter *f)
{
	if (!(f)->arg_str[0] && !(f)->precision.value)
		return (1);
	return (0);
}

static int	sf_will_be_zero_padded(t_formatter *f, int curr_width)
{
	if (!sf_will_print_nothing(f))
	{
		return ((f->precision.value < f->width.value) &&
		f->precision.value > curr_width);
	}
	return (0);
}

static int	sf_n_space_pad_calc(t_formatter *f, int curr_width)
{
	int space_pad;

	space_pad = 0;
	if (f->precision.value != -1 && f->precision.value < f->width.value)
	{
		if (sf_will_be_zero_padded(f, curr_width))
			space_pad = (f->width.value - f->precision.value) - curr_width;
		else
			space_pad = f->width.value - curr_width;
	}
	else if (f->precision.value != -1)
	{
		if (!(f->precision.value > f->width.value))
			space_pad = f->width.value - curr_width;
	}
	else
	{
		space_pad = f->width.value - curr_width;
	}
	if (!sf_will_print_nothing(f) && !sf_will_be_zero_padded(f, curr_width))
		space_pad -= pf_n_sign(&f, 0);
	else
		space_pad += 1;
	return (space_pad < 0) ? 0 : space_pad;
}

void		sf_n_set(t_formatter *f, int *space_pad, int *zero_pad)
{
	int curr_width;

	if (!(f)->arg_str[0])
	{
		*zero_pad = 0;
		*space_pad = (f->width.value == -1) ? 0 : f->width.value;
		return ;
	}
	curr_width = s_len(f->arg_str);
	if (f->arg_str[0] == '-')
	{
		curr_width -= 1;
	}
	*zero_pad = sf_n_zero_pad_calc(f, curr_width);
	*space_pad = sf_n_space_pad_calc(f, curr_width + *zero_pad);
}
