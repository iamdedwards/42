/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_v_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:19:01 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:08 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*s_v_to_lst(char **strs)
{
	t_list			*x;
	int				i;

	i = 0;
	x = NULL;
	while (strs[i][0] && strs[i])
	{
		l_push(&x,
		l_new(strs[i], sizeof(char *)));
		i++;
	}
	return (x);
}
