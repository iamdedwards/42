/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 12:50:47 by dedwards          #+#    #+#             */
/*   Updated: 2016/06/13 11:58:12 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	c_is_upper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
