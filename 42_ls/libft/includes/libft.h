/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:18:06 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 15:53:45 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "libft_includes.h"
# include "libft_macro.h"
# include "libft_typedefs.h"
# include "cft.h"
# include "lft.h"
# include "sft.h"
# include "itosft.h"
# include "initft.h"
# include "ioft.h"
# include "mapft.h"
# include "s_format.h"

int				i_len(int n);
int				i_tens(int n);
void			x_del(void **ap);
void			stall(long n);
int				i_in_iv(int *i_ref, int search, int len);
char			*s_move(char *s, int n);
void			l_s_iter(t_list **l_ref, int (*f)(int c));
#endif
