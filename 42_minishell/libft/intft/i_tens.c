/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_tens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:00:33 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:00:34 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		i_tens(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i *= 10;
	return (i);
}
