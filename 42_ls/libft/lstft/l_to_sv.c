/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_to_sv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 15:37:18 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**l_to_strs(t_list *x)
{
	char			**strs;
	int				i;

	i = 0;
	strs = (char **)malloc(sizeof(char *) * l_count(x) + 1);
	while (x)
	{
		strs[i++] = s_dup(x->content);
		x = x->next;
	}
	strs[i] = s_new(0);
	return (strs);
}
