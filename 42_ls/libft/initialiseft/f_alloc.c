/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_alloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:53:03 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:53:17 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	*f_alloc(float value)
{
	float *ref;

	ref = (float *)malloc(sizeof(float));
	*ref = value;
	return (ref);
}
