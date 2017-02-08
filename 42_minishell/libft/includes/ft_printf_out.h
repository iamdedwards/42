/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_out.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 17:39:27 by dan               #+#    #+#             */
/*   Updated: 2016/07/12 20:07:33 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_OUT_H
# define FT_PRINTF_OUT_H
# include "s_format.h"

int		pf_n_sign(t_formatter **f,
		void (*out_sign)(t_formatter **f, char *sign));
int		pf_direct(t_formatter **f);
int		pf_n(t_formatter **f);
int		pf_s(t_formatter **f);
int		pf_c(t_formatter **f);
int		pf_put_unformatted(t_formatter **f, const char *s, int n);
void	pf_std_out_padding(t_formatter **f, char c, int n);
void	pf_std_out_arg(t_formatter **f);
void	pf_std_out_sign(t_formatter **f, char *s);
#endif
