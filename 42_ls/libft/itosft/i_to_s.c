/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_to_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 13:48:28 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/14 13:48:47 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*i_to_s(int n)
{
	return (i_to_s_base(n, 10));
}
