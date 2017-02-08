/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_to_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 13:44:33 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/25 17:12:52 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*short_to_s_base(short ll, unsigned int base)
{
	t_list			*ret;
	int				sign;
	unsigned short	yep;
	unsigned short	wow;

	ret = NULL;
	if (!ll)
		return (s_dup("0"));
	sign = (ll < 0) ? 1 : 0;
	ll = (ll < 0) ? -ll : ll;
	wow = (unsigned short)ll;
	while (wow != 0)
	{
		yep = wow % base;
		l_add(&ret, l_new_s(c_to_s(yep + ((yep > 9) ? 55 : '0'))));
		wow = wow / base;
	}
	if (sign)
		l_add(&ret, l_new_s(c_to_s('-')));
	return ((ll == 0) ? s_dup("0") : lxx_to_s(&ret));
}
