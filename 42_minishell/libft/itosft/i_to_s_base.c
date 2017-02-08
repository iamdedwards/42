/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_to_s_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 13:47:37 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/25 17:11:43 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		i_to_s_base_work(t_list **l_ref, unsigned int ll,
unsigned int base)
{
	int				fig;

	while (ll != 0)
	{
		fig = ll % base;
		if (fig > 9)
			l_add(l_ref, l_new_s(c_to_s(fig + 55)));
		else
			l_add(l_ref, l_new_s(c_to_s(fig + 48)));
		ll /= base;
	}
}

char			*i_to_s_base(int ll, unsigned int base)
{
	t_list			*ret;
	int				sign;

	if (!ll)
		return (s_dup("0"));
	ret = NULL;
	sign = (ll < 0) ? 1 : 0;
	ll = (ll < 0) ? -ll : ll;
	i_to_s_base_work(&ret, ll, base);
	if (sign)
		l_add(&ret, l_new_s(c_to_s('-')));
	return (lxx_to_s(&ret));
}

char			*ui_to_s_base(unsigned int ll, unsigned int base)
{
	t_list			*ret;

	if (!ll)
		return (s_dup("0"));
	ret = NULL;
	i_to_s_base_work(&ret, ll, base);
	return (lxx_to_s(&ret));
}

char			*ucval_to_s_base(unsigned char ll, unsigned int base)
{
	t_list			*ret;

	if (!ll)
		return (s_dup("0"));
	ret = 0;
	i_to_s_base_work(&ret, ll, base);
	return (lxx_to_s(&ret));
}

char			*ushort_to_s_base(unsigned short ll, unsigned int base)
{
	t_list			*ret;

	if (!ll)
		return (s_dup("0"));
	ret = 0;
	i_to_s_base_work(&ret, ll, base);
	return (lxx_to_s(&ret));
}
