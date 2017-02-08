/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_to_sv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/31 10:24:42 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**l_to_sv(t_list *x)
{
	char			**strs;
	int				i;

	i = 0;
	strs = (char **)malloc(sizeof(char *) * l_count(x) + 1);
	while (x)
	{
		strs[i] = s_dup(x->content);
		x = x->next;
		i++;
	}
	strs[i] = 0;
	return (strs);
}
