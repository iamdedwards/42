/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format_type_funcs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 11:14:27 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/13 11:31:17 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FORMAT_TYPE_FUNCS_H
# define S_FORMAT_TYPE_FUNCS_H
# include "s_format.h"

typedef char	*(*t_ld_to_s_func)(unsigned long, unsigned int);
typedef char	*(*t_lld_to_s_func)(unsigned long long, unsigned int);
typedef char	*(*t_d_to_s_func)(unsigned int, unsigned int);
typedef char	*(*t_to_s_func)(unsigned long long, unsigned int);
typedef void	(*t_varg_func)(t_formatter **, va_list *);
typedef int		(*t_unf_func)(t_formatter **, const char *, int);
typedef int		(*t_form_func)(t_formatter **);
typedef void	(*t_sf_option_func)(t_formatter **);
#endif
