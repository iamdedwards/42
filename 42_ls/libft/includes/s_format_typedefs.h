/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format_typedefs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 17:04:35 by dan               #+#    #+#             */
/*   Updated: 2016/07/20 20:59:08 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FORMAT_TYPEDEFS_H
# define S_FORMAT_TYPEDEFS_H
# define L_AS_FMTR(a) ((t_formatter *)a->content)
# define LFRF(a) (t_formatter **)&(a->content)
# include "s_format.h"

typedef struct				s_str_section_to_int
{
	t_section				limits;
	int						value;
}							t_str_section_to_int;

typedef struct				s_formatter
{
	int						fd;
	char					*raw;
	int						parser_position;
	int						list;
	int						vector;
	int						pad_right;
	int						plus;
	int						zero;
	int						space;
	int						hash;
	t_str_section_to_int	width;
	t_str_section_to_int	precision;
	t_str_section_to_int	size;
	t_str_section_to_int	type;
	char					*arg_str;
	int						before;
	int						getter;
	int						after;
	t_list					*l_arg_strs;
	t_list					*l_formatted;
}							t_formatter;

typedef char	*(*t_stringer)(void *);
typedef char	*(*t_ld_to_s_func)(unsigned long, unsigned int);
typedef char	*(*t_lld_to_s_func)(unsigned long long, unsigned int);
typedef char	*(*t_d_to_s_func)(unsigned int, unsigned int);
typedef char	*(*t_to_s_func)(unsigned long long, unsigned int);
typedef void	(*t_varg_func)(t_formatter **, va_list *);
typedef int		(*t_unf_func)(t_formatter **, const char *, int);
typedef int		(*t_form_func)(t_formatter **);
typedef void	(*t_sf_option_func)(t_formatter **);

typedef struct				s_t_varg_func_map
{
	char					*keys;
	t_varg_func				getter;
}							t_varg_func_map;

typedef struct				s_get_d_map
{
	int						size;
	int						is_signed;
	t_d_to_s_func			d_to_s;
	t_ld_to_s_func			ld_to_s;
	t_lld_to_s_func			lld_to_s;
}							t_get_d_map;

typedef struct				s_sf_option_map
{
	char					flag;
	int						*option;
}							t_sf_option_map;
#endif
