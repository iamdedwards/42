/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_haschar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:54 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:06 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				s_n_haschar(char *tab, int c, int until)
{
	int				i;

	i = 0;
	while (tab[i] && until--)
	{
		if (tab[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int				s_haschars(const char *tab, char *cs)
{
	int				ret;
	int				i;

	i = 1;
	if (cs == 0 || tab == 0)
		return (-1);
	ret = s_haschar(tab, cs[0]);
	while (cs[i])
	{
		ret = ret && s_haschar(tab, cs[i]);
		i++;
	}
	return (ret);
}

int				s_haschar(const char *tab, int c)
{
	int				i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}
