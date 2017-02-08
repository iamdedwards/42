/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:56 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:08 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**s_split(char *s, char *split)
{
	t_list			*list;

	list = l_split(s, split);
	return (l_to_sv(list));
}

char			**s_dissect(char *s, char *split)
{
	t_list			*list;

	list = l_dissect(s, split);
	return (l_to_sv(list));
}
