/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 12:50:47 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/28 12:23:09 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		c_is_non_alnum(int c)
{
	return (!c_is_alnum(c));
}

int		c_is_alnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
