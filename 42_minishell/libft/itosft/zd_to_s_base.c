/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zd_to_s_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 13:50:40 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/25 17:12:51 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*zd_to_s_base(size_t ll, unsigned int base)
{
	t_list			*ret;
	size_t			yep;
	size_t			wow;

	if (!ll)
		return (s_dup("0"));
	ret = NULL;
	wow = (size_t)ll;
	while (wow != 0)
	{
		yep = wow % base;
		l_add(&ret, l_new_s(c_to_s(yep + ((yep > 9) ? 55 : '0'))));
		wow = wow / base;
	}
	return ((ll == 0) ? s_dup("0") : lxx_to_s(&ret));
}
