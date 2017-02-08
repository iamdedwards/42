/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 16:42:58 by dan               #+#    #+#             */
/*   Updated: 2016/08/10 11:20:20 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FORMAT_H
# define S_FORMAT_H
# include "libft.h"
# include "s_format_typedefs.h"
# include "s_format_defines.h"
# include "s_format_out.h"
# include "s_format_type_funcs.h"
# include "trace.h"

# define SF_LINUX 0

void			sf_get_arg_from_void(t_formatter **f_ref, va_list *args);
char			*s_format(const char *s, ...);
int				ft_printf_fd(int fd, const char *s, ...);
int				pf_fd_c_or_s(t_formatter **f);
int				pf_fd_n(t_formatter **f);
void			pf_arg_proto(t_formatter **f, int fd);
int				sf_direct_proto(t_formatter **f_ref,
				int (*c_or_s_func)(t_formatter **),
				int (*n_func)(t_formatter **));
void			escape_code_put(char *btw, int len);
void			sf_put_rgb(char *key, int modif);
int				put_if_mapped(char *key, char modif, t_s_s_map *map, char flag);
void			put_func_if_mapped(char *key);
t_s_s_map		*style_map(void);
t_s_s_map		*color_map(void);
char			pf_move_map(char *key);
int				ft_printf(const char *fs, ...);
int				pf_direct(t_formatter **f_ref);
int				pf_n_sign(t_formatter **f,
				void (*out_sign)(t_formatter **f, char *sign));
char			*sf_rgb_code(int r, int g, int b);
void			pf_sign(t_formatter **f, char *s);
void			pf_arg(t_formatter **f);
void			pf_padding(t_formatter **f, char c, int n);
int				pf_color(t_formatter **f, const char *s, int n);
void			put_escapes(char *s, char *start, char *end,
				void (*escape)(char *between, int len));
int				sf_n(t_formatter **f);
char			*sf_rgb(int r, int g, int b);
void			sf_s_list_numbers(t_formatter **f_ref,
				void (*out)(t_formatter **, char, int));
char			*sf_get_wrap(int is_wrap, va_list *args);
char			*s_format(const char *format_string, ...);
void			populate_formatter(t_list **vlst_ref);
t_formatter		*as_formatter(t_list *l);
t_formatter		*sf_init_formatter(t_formatter *f, char *fs);
t_list			*sf_get_formats(const char *format_copy, int *start_pos);
void			add_size(t_formatter **f, t_str_section_to_int ttsi);
void			add_precision(t_formatter **f, t_str_section_to_int s);
void			add_size(t_formatter **f, t_str_section_to_int s);
void			add_type(t_formatter **f, t_str_section_to_int s);
void			add_min_width(t_formatter **f, t_str_section_to_int s);
int				sf_get_arg(t_formatter **f_ref, va_list *args);
void			sf_get_arg_s(t_formatter **f_ref, va_list *args);
void			sf_get_arg_ws(t_formatter **f_ref, va_list *args);
void			sf_get_arg_wchar(t_formatter **f_ref, va_list *args);
void			sf_get_arg_char(t_formatter **f_ref, va_list *args);
void			sf_get_arg_float(t_formatter **f_ref, va_list *args);
void			sf_get_num(t_formatter **f_ref, va_list *args);
void			sf_n_set(t_formatter *f, int *space_pad, int *zero_pad);
int				pf_n(t_formatter **f);
int				sf_n(t_formatter **f);
int				sf_iter(const char *format_string, t_list **f_all,
				int (*sf_use_unformatted_s)(t_formatter **, const char *, int),
				int (*sf_use_formatter)(t_formatter **));
int				sf_direct(t_formatter **f);
int				sf_s_proto(t_formatter **f_ref,
				void (*out_padding)(t_formatter **, char, int),
				void (*out_arg)(t_formatter **));
int				sf_n_proto(t_formatter **f,
				void (*out_padding)(t_formatter **f, char c, int n),
				void (*out_sign)(t_formatter **f, char *s),
				void (*out_arg)(t_formatter **f));
t_list			*s_format_proto(const char *format_string, va_list *args);
void			sf_get_arg_pointer(t_formatter **f_ref, va_list *args);
#endif
