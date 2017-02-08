/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 18:43:38 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/13 15:12:45 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITFT_H
# define INITFT_H
# include "libft.h"

void			b_all_zero(int nargs, void ***argbag);
void			i_all_zero(int nargs, int **iv);
float			*f_alloc(float value);
void			*init_zero(size_t size);
void			*init_val(int val, size_t size);
void			buff_val(char *buff, int val, size_t len);
#endif
