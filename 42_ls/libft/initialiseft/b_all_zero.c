/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_all_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 19:04:41 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 14:04:08 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			b_all_zero(int nargs, void ***argbag)
{
	int				i;

	i = 0;
	while (nargs--)
		*argbag[nargs] = 0;
}

void			i_all_zero(int nargs, int **iv)
{
	int				i;

	i = 0;
	while (nargs--)
		*iv[nargs] = 0;
}
