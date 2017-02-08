/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_get_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:49:22 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:52:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_get_d_map	get_d_map(int size, int is_signed)
{
	int					i;
	static t_get_d_map	map[] = {
		{SF_CHAR, 1, (t_d_to_s_func)cval_to_s_base, 0, 0},
		{SF_CHAR, 0, (t_d_to_s_func)ucval_to_s_base, 0, 0},
		{SF_SHORT, 1, (t_d_to_s_func)short_to_s_base, 0, 0},
		{SF_SHORT, 0, (t_d_to_s_func)ushort_to_s_base, 0, 0},
		{SF_LONG, 1, 0, (t_ld_to_s_func)l_to_s_base, 0},
		{SF_LONG, 0, 0, (t_ld_to_s_func)ul_to_s_base, 0},
		{SF_LONGLONG, 1, 0, 0, (t_lld_to_s_func)ll_to_s_base},
		{SF_LONGLONG, 0, 0, 0, (t_lld_to_s_func)ull_to_s_base},
		{SF_SIZET, 1, 0, (t_ld_to_s_func)zd_to_s_base, 0},
		{SF_SIZET, 0, 0, (t_ld_to_s_func)zd_to_s_base, 0},
		{SF_INTMAXT, 1, 0, 0, (t_lld_to_s_func)ll_to_s_base},
		{SF_INTMAXT, 0, 0, 0, (t_lld_to_s_func)ull_to_s_base}, {0, 0, 0, 0, 0}};

	i = 0;
	while (map[i].size)
	{
		if (map[i].size == size && map[i].is_signed == is_signed)
			return (map[i]);
		i++;
	}
	return ((is_signed) ?
	(t_get_d_map){SF_SIZELESS, 1, (t_d_to_s_func)i_to_s_base, 0, 0}
	: (t_get_d_map){SF_SIZELESS, 0, (t_d_to_s_func)ui_to_s_base, 0, 0});
}

static char			*sf_lst_num(void *arg, t_get_d_map *map, int base)
{
	if (map->d_to_s)
		return (map->d_to_s(*(unsigned int *)arg, base));
	else if (map->ld_to_s)
		return (map->d_to_s(*(unsigned long *)arg, base));
	else
		return (map->d_to_s(*(unsigned long long *)arg, base));
}

void				sf_get_num_simp(t_formatter **f, va_list *args,
	t_get_d_map *map, int base)
{
	char	*tmp;

	tmp = NULL;
	if (map->d_to_s)
		tmp = map->d_to_s(va_arg(*args, unsigned int), base);
	else if (map->ld_to_s)
		tmp = map->ld_to_s(va_arg(*args, unsigned long), base);
	else if (map->lld_to_s)
		tmp = map->lld_to_s(va_arg(*args, unsigned long long), base);
	if (s_equals(tmp, "0") && ((*f)->precision.value == 0))
	{
		tmp[0] = '\0';
	}
	l_push_s(&(*f)->l_arg_strs, tmp);
}

void				sf_get_num_out(t_formatter **f, va_list *args,
	t_get_d_map *map, int base)
{
	t_list	*l;
	char	*before;
	char	*tmp;
	char	*after;

	before = sf_get_wrap((*f)->before, args);
	if ((*f)->list)
	{
		l = va_arg(*args, t_list *);
		after = sf_get_wrap((*f)->after, args);
		while (l)
		{
			tmp = sf_lst_num(l->content, map, base);
			l_push_s(&(*f)->l_arg_strs, sv_n_join((char *[])
			{before, tmp, after}, 3));
			l = l->next;
			s_del(&tmp);
		}
	}
	else
	{
		sf_get_num_simp(f, args, map, base);
	}
}

void				sf_get_num(t_formatter **f, va_list *args)
{
	t_get_d_map	map;
	int			base;
	int			is_ui;
	int			type;

	type = (*f)->type.value | ' ';
	is_ui = type == 'u' ||
	(s_haschar("xo", type));
	base = (type == 'b') ? 2 : 10;
	base = (type == 'x') ? 16 : base;
	if (type == 'o')
		base = 8;
	map = get_d_map((*f)->size.value, !is_ui);
	sf_get_num_out(f, args, &map, base);
}
