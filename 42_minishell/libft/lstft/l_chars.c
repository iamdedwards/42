/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_chars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/14 12:34:22 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_chars(char *str)
{
	t_list			*lst;

	lst = NULL;
	while (*str)
	{
		l_push(&lst, l_new(c_to_s(*str++), 1));
	}
	return (lst);
}