/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cval_to_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 13:45:14 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/25 17:12:52 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*cval_to_s_base(char ll, unsigned int base)
{
	t_list			*ret;
	int				sign;
	unsigned char	yep;
	unsigned char	wow;

	if (!ll)
		return (s_dup("0"));
	ret = NULL;
	sign = (ll < 0) ? 1 : 0;
	ll = (ll < 0) ? -ll : ll;
	wow = (unsigned char)ll;
	while (wow != 0)
	{
		yep = wow % base;
		l_add(&ret, l_new_s(c_to_s(yep + ((yep > 9) ? 55 : '0'))));
		wow = wow / base;
	}
	if (sign)
		l_add(&ret, l_new_s(c_to_s('-')));
	return (lxx_to_s(&ret));
}
