/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sft.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 19:13:06 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/28 15:01:07 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFT_H
# define SFT_H
# include "libft.h"

int				s_has_other_than(char *s,
				char *ok_chars);
int				s_has(char *s, int (*f)(int));
int				s_hasi(char *s, int (*f)(int));
char			*s_tail(char *s, int n);
char			*s_move(char *s, int n);
char			*s_between(char *s, char *l, char *r);
char			*sv_n_join(char **s_ref, size_t n);
char			*unicode_to_utf8(wchar_t wc);
char			*ws_to_s(wchar_t *ws);
int				sv_len(char **s_ref);
char			*sv_join(char **s_ref);
void			s_set(char **current, char *newval);
char			*s_ifnull(char *test, char *defaulted);
int				s_haschar(const char *tab, int c);
int				s_haschars(const char *tab, char *cs);
int				s_n_haschar(char *tab, int c, int until);
char			*s_cat(char *dest, const char *src);
char			*s_char(const char *str, int c);
void			s_clr(char *s);
char			*s_n_clr(char *s, size_t n);
int				s_cmp(const char *s1, const char *s2);
char			*s_cpy(char *dest, const char *src);
void			s_del(char **as);
char			*s_dup(const char *str);
int				s_equals(char *s1, char *s2);
char			*s_inner(const char *str, const char *substr);
char			*s_join(char const *s1, char const *s2);
char			*s_padl(char *s, char c, int l);
char			*s_padr(char *s, char c, int l);
size_t			s_len(const char *str);
char			*s_map(char const *s, char (*f)(char));
char			*s_filter(char *s, int (*f)(int));
char			*s_mapi(char const *s, char (*f)(unsigned int, char));
char			*s_n_cat(char *dest, const char *src, size_t n);
int				s_n_cmp(const char *s1, const char *s2, size_t n);
char			*s_n_cpy(char *dest, const char *src, size_t n);
char			*s_n_dup(const char *src, size_t n);
int				s_n_equals(char const *s1, char const *s2, size_t n);
char			*s_n_inner(const char *str, const char *substr, size_t n);
size_t			s_nchar(const char *str, char c);
char			*s_init(int val, size_t size);
char			*s_new(size_t size);
size_t			s_nto_c(const char *s, char c);
int				s_nto_inner(char *s, char *s2);
size_t			s_nto_pass_char(const char *s, char c);
char			**s_split(char *s, char *split);
char			*s_dup_squeeze(char *s, char tosqueeze);
void			s_squeeze(char **s, char tosqueeze);
void			s_subber(char **s, char *rep, char *ins);
void			s_subber_g(char **s, char *rep, char *ins);
char			*s_dup_subber(char *s, char *rep, char *ins);
char			*s_dup_subber_g(char *s, char *rep, char *ins);
char			**s_dissect(char *s, char *split);
char			*s_sub(char const *s, unsigned int start, size_t len);
char			*s_trim(char const *s);
char			*s_iter(char *s, int (*f)(int));
char			*sv_reduce(char **strings);
int				s_to_i(const char *str);
unsigned int	s_n_to_ui(char *str, unsigned int i);
#endif
