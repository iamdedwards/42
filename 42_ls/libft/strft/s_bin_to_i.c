/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bin_to_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 19:11:52 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 19:11:53 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				i_binary_to_i(char *bin)
{
	int				i;
	int				toint;
	int				rest;
	int				multiplier;

	multiplier = 1;
	i = 0;
	while (bin[i] == '0')
		i++;
	toint = s_to_i(&bin[i]);
	i = 0;
	while (toint != 0)
	{
		rest = toint % 10;
		i = i + rest * multiplier;
		multiplier *= 2;
		toint = toint / 10;
	}
	return (i);
}

char			*i_hexa(unsigned int n)
{
	return (ui_to_s_base(n, 16));
}
