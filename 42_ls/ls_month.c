/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_month.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 19:01:37 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/11 16:17:21 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					month(char *s)
{
	char			*ifnfound;
	static char		*map[] = {
		0,
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
		0,
	};
	int				i;

	i = 1;
	while (map[i])
	{
		if (s_n_equals(map[i], s, 3))
			return (i);
		i++;
	}
	ifnfound = s_format("date:%s not found:", s);
	TX(ifnfound);
	return (-1);
}
