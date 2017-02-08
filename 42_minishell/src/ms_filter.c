/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:32 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 13:30:54 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list				*l_s_n_equals(t_list *x, void *args)
{
	int				*n;
	char			*s;
	void			**params;

	params = args;
	s = params[0];
	n = params[1];
	if (s_n_equals(x->content, s, *n))
		return (l_new(s_dup(x->content), x->index));
	return (0);
}

t_list				*l_s_inner(t_list *x, void *args)
{
	char			*s;

	s = args;
	if (s_inner(s, x->content))
		return (l_new(s_dup(x->content), x->index));
	return (0);
}
