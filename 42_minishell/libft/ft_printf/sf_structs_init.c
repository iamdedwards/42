/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_structs_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 11:11:21 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/12 13:49:30 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_formatter					*as_formatter(t_list *l)
{
	t_formatter	*f;

	if (!l)
		return (NULL);
	f = (l->content);
	return (f);
}

static t_str_section_to_int	t_ssti_default(void)
{
	t_str_section_to_int	s;

	s.limits.start = -1;
	s.limits.end = -1;
	s.value = -1;
	return (s);
}

t_formatter					*sf_init_formatter(t_formatter *f, char *fs)
{
	f->raw = fs;
	f->size = t_ssti_default();
	f->type = t_ssti_default();
	f->width = t_ssti_default();
	f->precision = t_ssti_default();
	return (f);
}
