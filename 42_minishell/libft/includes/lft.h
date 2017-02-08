/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 10:18:53 by dan               #+#    #+#             */
/*   Updated: 2016/10/31 16:55:20 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_H
# define LFT_H
# include "libft.h"
# define CONTENT_OF(a, cast) ((cast)((a)->content))
# define CONTENT_OF_P(a, cast) ((cast)((*a)->content))
# define L_STR(a) CONTENT_OF(a, char *)

typedef t_list	*(*t_filter_with)(t_list *, void *);
typedef void	*(*t_reducer)(void *, void *);
char			**lx_to_sv(t_list **x);
t_list			*l_filter_with(t_list *l,
				t_list *(*f)(t_list *, void *), void *arg);
t_list			*l_where(t_list **lst, int (*f)(t_list *));
void			l_remove_if(t_list **l, int (*f)(t_list *), void (*g)(void **));
void			l_del_from(t_list **lst, int untill);
t_list			*l_n_dup(t_list *l, int untill);
t_list			*l_slice(t_list *l, int start, int end);
int				l_has_c(t_list *s, char c);
int				l_push_sort(t_list **ref, t_list *newl,
				int (*sorter_ref)(t_list *, t_list *));
int				l_push_sort_content(t_list **ref, t_list *newl,
				int (*sorter_ref)(void *, void *));
t_list			*l_new_f(float val);
t_list			*l_new_i(int i);
t_list			*l_dup(t_list *l);
t_list			*l_snap_after(char *string, char *snapper);
t_list			*l_section(char *string, int section_width);
t_list			*l_first_by_index(t_list *x, size_t index);
t_list			*l_find(t_list *x, size_t index);
void			l_destroy(t_list **a_ref, void (*f)(void **));
t_list			*l_filteri(t_list *l,
				t_list *(*f)(t_list *, int));
t_list			*l_filter_sv(char **sv, t_list *(*f)(char *));
t_list			*l_filter(t_list *l, t_list *(*f)(t_list *));
char			**l_to_sv(t_list *x);
int				l_add(t_list **alst, t_list *newl);
t_list			*l_chars(char *str);
int				l_count(t_list *tmp);
void			l_destroy_content(void **content);
t_list			*l_div(t_list *l, t_list *(*either)(t_list *));
size_t			l_each_s_len(t_list *x);
t_list			*l_goto(t_list *lst, int pos);
t_list			*l_grab(t_list **x, int i);
int				l_has(t_list *lst, int (*f)(void *));
int				l_last_having(t_list *lst, int (*f)(void *));
t_list			*l_insert(t_list **a, t_list *x, int pos);
t_list			*l_last(t_list *a);
t_list			*l_map(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*l_new(void const *content, size_t index);
t_list			*l_new_s(char *content);
t_list			*l_new_l(t_list *l);
t_list			*l_previous(t_list **list, t_list **ref);
int				l_push(t_list **alst, t_list *newl);
int				l_push_s(t_list **alst, char *s);
int				l_push_sv(t_list **alst, char **sv);
void			*l_reduce(t_list *a, void *init,
				void *(*f)(void *, void *));
void			l_hop(t_list **lthis, t_list *newun);
char			*l_to_s(t_list *a);
char			*lx_to_s(t_list **a);
char			*lxx_to_s(t_list **a);
int				l_refindex(t_list **list, t_list **ref);
void			l_remove(t_list **a_ref, t_list **element_ref,
				void (*f)(void **));
t_list			*l_reverse(t_list **list);
t_list			*l_split(char *s, char *split);
t_list			*l_dissect(char *s, char *split);
t_list			*l_grab_ref(t_list **head, t_list **elem);
int				l_index_pos(t_list *x, size_t index);
t_list			*l_grab_index(t_list **head, size_t index);
void			each_l(t_list **x, void (*f)(t_list **));
void			each_l_using(t_list **x, void (*f)(t_list **, void *),
				void *args);
void			iter_l_content(t_list *x, void (*f)(void *));
int				wherein_l_content(t_list *x,
				int (*f)(void *, void *), void *arg);
t_list			*l_init_iv(int *array, size_t size);
t_list			*l_init_fv(float *array, size_t size);
t_list			*l_init_sv(char **sv);
int				l_max_i(t_list *l, int (*getter)(t_list *l));
size_t			l_sum_size(t_list *l, size_t (*getter)(t_list *l));
#endif
