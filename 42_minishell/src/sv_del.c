/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:40 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:07:50 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				sv_del(char ***sv)
{
	int				i;

	i = 0;
	while ((*sv) && (*sv)[i] != NULL)
	{
		if (*sv)
			s_del(&(*sv)[i++]);
	}
	if ((*sv))
		free(*sv);
	*sv = NULL;
}