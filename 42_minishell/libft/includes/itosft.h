/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itosft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:39:27 by dan               #+#    #+#             */
/*   Updated: 2016/07/27 18:26:18 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOSFT_H
# define ITOSFT_H
# include "libft.h"

char				*cval_to_s_base(char n, unsigned int base);
char				*f_to_s(float f, unsigned int precision);
char				*i_binary(int n);
char				*i_hexa_negative(unsigned long long n);
char				*i_to_s(int n);
char				*i_to_s_base(int ll, unsigned int base);
char				*ll_to_s_base(long long n, unsigned int base);
char				*short_to_s_base(short ll, unsigned int base);
char				*ucval_to_s_base(unsigned char ll, unsigned int base);
char				*ui_to_s_base(unsigned int ll, unsigned int base);
char				*ul_to_s_base(unsigned long ll, unsigned int base);
char				*l_to_s_base(long ll, unsigned int base);
char				*ull_to_s_base(unsigned long long ll, unsigned int base);
char				*ushort_to_s_base(unsigned short n, unsigned int base);
char				*zd_to_s_base(size_t ll, unsigned int base);
int					i_binary_to_i(char *bin);
long long			smaxof(size_t size);
unsigned long long	umaxof(size_t size);
int					f_to_i(float n);
char				*f_to_i_precise_work(char *fstr, int precise, int offset);
int					f_to_i_precise(float n, int precise);
#endif
