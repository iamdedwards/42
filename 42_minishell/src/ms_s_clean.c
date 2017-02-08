/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_s_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:39 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 11:11:59 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_s_clean_what_it_was_all_about(char **s, char *trimmed)
{
	s_del(s);
	*s = trimmed;
	if (*s_tail(*s, 1) == ' ')
		*s_tail(*s, 1) = 0;
}

void				ms_s_clean(char **s)
{
	char			*trimmed;
	int				on;
	int				i;
	int				j;

	i = 0;
	j = 0;
	trimmed = s_new(s_len(*s));
	on = 0;
	while ((*s)[i])
	{
		if (on && s_haschar((char[]){' ', '\t', 26}, (*s)[i]))
		{
			trimmed[j++] = ' ';
			on = 0;
		}
		else if (!s_haschar((char[]){' ', '\t', 26}, (*s)[i]))
		{
			on = 1;
			trimmed[j++] = (*s)[i];
		}
		i++;
	}
	ms_s_clean_what_it_was_all_about(s, trimmed);
}
