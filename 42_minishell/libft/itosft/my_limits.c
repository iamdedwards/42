/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_limits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 14:49:44 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 17:38:47 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	umaxof(size_t size)
{
	unsigned long long ret;

	ret = (((0x1ULL << ((size * 8ULL) - 1ULL)) - 1ULL) |
			(0xFULL << ((size * 8ULL) - 4ULL)));
	return (ret);
}

long long			smaxof(size_t size)
{
	long long ret;

	ret = (((0x1ULL << ((size * 8ULL) - 1ULL)) - 1ULL) |
			(0x7ULL << ((size * 8ULL) - 4ULL)));
	return (ret);
}
