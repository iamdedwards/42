/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_snap_after.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 13:56:14 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/14 13:56:22 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_snap_after(char *s, char *split)
{
	t_list			*list;
	int				len;
	int				i;

	i = 0;
	list = NULL;
	len = s_len(split);
	while (s[i])
	{
		i += s_nto_c(s, split[0]);
		if (s_n_cmp(&s[i], split, len) == 0)
		{
			l_push_s(&list, (s_n_dup(s, i)));
			l_push_s(&list, s_n_dup(&s[i + len], s_len(&s[i + len])));
			return (list);
		}
		i++;
	}
	return (NULL);
}
