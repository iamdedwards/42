/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_squeeze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:56 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 19:10:58 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*s_dup_squeeze(char *s, char tosqueeze)
{
	int				start;
	int				end;
	char			*replace;

	if (!s_haschar(s, tosqueeze))
		return (s);
	start = s_nto_c(s, tosqueeze);
	end = s_nto_pass_char(&s[start], tosqueeze);
	replace = init_val(tosqueeze, end);
	return (s_dup_subber(s, replace, (char[]){tosqueeze, 0}));
}

void		s_squeeze(char **s, char tosqueeze)
{
	char *tmp;

	tmp = s_dup_squeeze(*s, tosqueeze);
	s_del(s);
	*s = tmp;
}
