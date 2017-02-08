/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_to_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 21:43:52 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/25 17:12:52 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		l_to_s_base_work(
	t_list **l_ref,
	unsigned long ll,
	unsigned int base)
{
	unsigned long	fig;

	while (ll != 0)
	{
		fig = ll % base;
		if (fig > 9)
		{
			l_add(l_ref, l_new_s(c_to_s(fig + 55)));
		}
		else
		{
			l_add(l_ref, l_new_s(c_to_s(fig + 48)));
		}
		ll /= base;
	}
}

char			*l_to_s_base(long ll, unsigned int base)
{
	t_list			*ret;
	int				sign;

	if (!ll)
		return (s_dup("0"));
	ret = NULL;
	sign = (ll < 0) ? 1 : 0;
	ll = (ll < 0) ? -ll : ll;
	l_to_s_base_work(&ret, ll, base);
	if (sign && base != 16)
		l_add(&ret, l_new_s(c_to_s('-')));
	return (lxx_to_s(&ret));
}

char			*ul_to_s_base(unsigned long ll, unsigned int base)
{
	t_list			*ret;

	if (!ll)
		return (s_dup("0"));
	ret = NULL;
	l_to_s_base_work(&ret, ll, base);
	return (lxx_to_s(&ret));
}
