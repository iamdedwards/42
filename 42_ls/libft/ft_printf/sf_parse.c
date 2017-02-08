/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 11:05:39 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:50 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				parser_analyse(t_formatter **f_ref, char *format_flags,
		int len_args)
{
	int				i;
	char			*to_parse;
	t_formatter		*f;

	f = *f_ref;
	to_parse = &f->raw[f->parser_position];
	i = 0;
	if (!f->raw[f->parser_position])
		return (0);
	while ((to_parse)[i] && s_haschar(format_flags, (to_parse)[i]))
	{
		i++;
		if (i == len_args || i == -len_args)
			break ;
	}
	if (!i || (len_args <= 0 && -i != len_args))
		return (0);
	f->parser_position += (i);
	return (1);
}

static int				parser_set_section(t_formatter **f_ref, char *flags,
int len_args,
void (*on_success)(t_formatter **, t_str_section_to_int))
{
	t_str_section_to_int	num_interpret;
	t_formatter				*f;

	f = *f_ref;
	num_interpret.limits.start = f->parser_position;
	if (parser_analyse(&f, flags, len_args))
	{
		num_interpret.limits.end = f->parser_position;
		if (on_success)
			on_success(f_ref, num_interpret);
		return (1);
	}
	return (0);
}

static void				parser_set_options(t_formatter **f_ref,
t_sf_option_map *map, int limit)
{
	int		j;
	int		i;
	char	*to_parse;

	i = 0;
	j = 0;
	to_parse = (*f_ref)->raw;
	while (to_parse[i] && limit)
	{
		while (map[j].flag)
		{
			if (map[j].flag == to_parse[i])
			{
				*map[j].option = 1;
			}
			j++;
		}
		j = 0;
		i++;
		limit--;
	}
}

static t_sf_option_map	*sf_option_map(t_formatter **f_ref)
{
	static t_sf_option_map map[] = {
		{'-', 0}, {'+', 0},
		{'0', 0}, {'#', 0},
		{' ', 0}, {'v', 0},
		{'@', 0}, {'^', 0},
		{'$', 0},
		{0, 0}
	};

	map[0].option = &(*f_ref)->pad_right;
	map[1].option = &(*f_ref)->plus;
	map[2].option = &(*f_ref)->zero;
	map[3].option = &(*f_ref)->hash;
	map[4].option = &(*f_ref)->space;
	map[5].option = &(*f_ref)->vector;
	map[6].option = &(*f_ref)->list;
	map[7].option = &(*f_ref)->before;
	map[8].option = &(*f_ref)->after;
	return (map);
}

void					populate_formatter(t_list **vlst_ref)
{
	t_list		*vlst;
	t_formatter	*f;
	static char	keys[] = "%sSiIdDuUfFxXoOcCpPbB>";
	int			prcise;

	vlst = *vlst_ref;
	f = as_formatter(vlst);
	parser_set_section(&f, " 0+-#v^$@", SF_PARSE_GREEDY, 0);
	parser_set_options(&f, sf_option_map(&f), f->parser_position);
	if (!parser_set_section(&f, "*", SF_PARSE_MAX_LEN(1), add_min_width))
		parser_set_section(&f, "0123456789", SF_PARSE_GREEDY, add_min_width);
	prcise = (parser_set_section(&f, ".", SF_PARSE_MAX_LEN(1), add_precision));
	if ((prcise) &&
	(0 == parser_set_section(&f, "*", SF_PARSE_MAX_LEN(1), add_precision)))
	{
		parser_set_section(&f, "0123456789", SF_PARSE_GREEDY, add_precision);
	}
	parser_set_section(&f, "llhh", SF_PARSE_MIN_LEN(2), add_size);
	parser_set_section(&f, "jzhl", SF_PARSE_MAX_LEN(1), add_size);
	if (!parser_set_section(&f, keys, SF_PARSE_MAX_LEN(1), add_type))
	{
		f = sf_init_formatter(f, f->raw);
		f->type.value = '!';
		f->type.limits.end = f->parser_position;
	}
}
