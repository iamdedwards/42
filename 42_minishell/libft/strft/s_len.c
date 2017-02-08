/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:55 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/16 16:39:08 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	s_len(const char *str)
{
	size_t size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}