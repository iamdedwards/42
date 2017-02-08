/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ioft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 10:30:59 by dan               #+#    #+#             */
/*   Updated: 2016/07/14 16:14:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOFT_H
# define IOFT_H
# include "libft.h"

void		ps_n_fd(const char *s, int fd, size_t n);
int			get_next_line(int fd, char **line);
int			s_get(int fd, char **line, char *untill);
char		**ft_sssplit(char *split, char *wthis);
int			ft_nsbtws(char *split, char *wthis);
void		p_lst(t_list *l);
void		pv(void *x);
void		pc(char c);
void		pc_fd(char c, int fd);
void		pnl(char const *s);
void		pnl_fd(char const *s, int fd);
void		pn(int n);
void		pn_fd(int n, int fd);
void		pc_repeat(char s, size_t n);
void		ps_untill(char *s, size_t size);
void		ps(const char *str);
void		ps_fd(const char *s, int fd);
void		sv_put_n(char **sv, size_t n);
#endif
