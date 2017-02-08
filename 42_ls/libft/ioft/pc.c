/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:05:33 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:05:38 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pc(char c)
{
	unsigned char uc;

	uc = (unsigned char)c;
	write(1, &uc, 1);
}

void	pc_repeat(char c, size_t n)
{
	while (n--)
		pc(c);
}
