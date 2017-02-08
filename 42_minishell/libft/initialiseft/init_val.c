/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 14:59:07 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/16 18:03:04 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*init_val(int val, size_t size)
{
	char	*buffer;
	size_t	i;

	i = 0;
	buffer = (char *)malloc(sizeof(char) * size);
	while (i < size)
	{
		buffer[i] = val;
		i++;
	}
	return (buffer);
}

void	*iv_alloc(int val, size_t size)
{
	return (init_val(val, size));
}

int		*i_alloc(int val)
{
	int				*ret;

	ret = (int *)malloc(sizeof(int));
	*ret = val;
	return (ret);
}
