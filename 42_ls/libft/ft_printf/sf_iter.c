/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:23:08 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			sf_iter_start(
					const char *fs, int idx, t_list *run)
{
	int				ret;
	int				type;

	if (!run)
		return (0);
	ret = (*&fs[idx] && (*&fs[idx] == '%' &&
			&fs[idx + 1] && (&fs[idx + 1] == (L_AS_FMTR(run))->raw)));
	if (ret)
		return (1);
	type = L_AS_FMTR(run)->type.value;
	if (((type == '%') && ((&L_AS_FMTR(run)->raw[1]) && &fs[idx + 1])) &&
	((&L_AS_FMTR(run)->raw[1]) == &fs[idx + 1]))
	{
		return (2);
	}
	return (0);
}

static int			sf_iter_sweep(const char *f_string, t_formatter **f_ref,
t_unf_func func)
{
	t_formatter		*f;
	int				len;
	int				ret;
	int				nc;

	nc = 0;
	ret = 0;
	len = s_len(f_string);
	f = *f_ref;
	if (&f->raw[f->type.limits.end - 1] != &f_string[s_len(f_string) - 1])
	{
		if (!&f_string[nc])
			return (ret);
		while (&f_string[(nc + (f->type.value == '!'))]
		!= &f->raw[f->type.limits.end + (f->type.value == '%')])
			nc++;
		ret += func(&f, &f_string[nc], len - (nc));
	}
	return (ret);
}

int					sf_iter(const char *fs, t_list **f_all,
					int (*unf)(t_formatter **, const char *, int n),
					int (*sf_use_formatter)(t_formatter **))
{
	char			idx[3];
	t_list			*run;
	int				ret;

	ret = 0;
	run = *f_all;
	buff_val(idx, 0, 2);
	idx[2] = s_len(fs);
	while (idx[0] < idx[2])
	{
		if ((sf_iter_start(fs, idx[0], run)))
		{
			ret += (idx[1]) ? unf(LFRF(run), &fs[idx[0] - idx[1]], idx[1]) : 0;
			ret += sf_use_formatter(LFRF(run));
			idx[0] += L_AS_FMTR(run)->type.limits.end;
			run = run->next;
			idx[1] = 0;
		}
		else
			idx[1]++;
		idx[0]++;
	}
	return (ret + sf_iter_sweep(fs, LFRF(l_last((*f_all))), unf));
}
