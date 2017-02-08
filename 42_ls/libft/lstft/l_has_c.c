/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_has_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 23:56:32 by dan               #+#    #+#             */
/*   Updated: 2016/07/18 00:04:20 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		l_has_c(t_list *s, char c)
{
	while (s)
	{
		if (s_haschar(s->content, c))
			return (1);
		s = s->next;
	}
	return (0);
}