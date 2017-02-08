/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:58:25 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/01 16:58:34 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_next_line(int fd, char **line)
{
	return (io_using(fd, line, GNL_READ));
}

void			dispose_lines(int fd)
{
	io_using(fd, 0, GNL_DISPOSE);
}
