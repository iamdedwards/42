/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:05:34 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/13 13:38:09 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ps(const char *str)
{
	while (*str)
	{
		pc(*str++);
	}
}

void			sv_put_n(char **sv, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
	{
		ps(sv[i]);
		i++;
	}
}

void			ps_untill(char *str, size_t untill)
{
	while (*str && untill--)
	{
		pc(*str++);
	}
}
