/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:05:34 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/14 16:14:26 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ps_fd(const char *s, int fd)
{
	while (*s)
		pc_fd((int)*s++, fd);
}

void	ps_n_fd(const char *s, int fd, size_t n)
{
	while (*s && n--)
	{
		pc_fd((int)*s++, fd);
	}
}
