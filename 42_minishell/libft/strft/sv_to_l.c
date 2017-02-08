/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_to_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:19:01 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:08 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*sv_to_l(char **sv)
{
	int				i;
	t_list			*ret;

	ret = NULL;
	i = 0;
	while (sv[i])
	{
		l_push(&ret, l_new_s(sv[i]));
		i++;
	}
	return (ret);
}
