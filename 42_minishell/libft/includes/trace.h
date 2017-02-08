/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:43:12 by dedwards          #+#    #+#             */
/*   Updated: 2016/09/29 14:59:47 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H
# include "../includes/s_format.h"
# define TO_STR(a) #a
# define LOGFUNC ft_printf
# define NOTRACE 0
# if NOTRACE == 0
#  define TCV(a, b, c) LOGFUNC("[%s]:%s[%d]%s%s", a, "\e[31m", b, "\e[0m", c)
#  define TCE(a, b, c) TCV(a, b, c)
#  define TEVEV(a, b) LOGFUNC(" \e[33m%s = \e[0m%s\n",  a, b)
#  define TEV(a, b, c, d, e) TCE(a, b, c); TEVEV(d, e)
# else
#  define TEV(a, b, c, d, e) ps("");
# endif
# if NOTRACE == 0
#  define T_BOOL_EVAL(a) LOGFUNC("%s : %s\n", #a, (a) ? "TRUE" : "FALSE");
# else
#  define T_BOOL_EVAL(a)
# endif
# define T_BOOL(a) T_BOOL_EVAL((a))
# define T_IS_NULL(a) T_BOOL(a == NULL)
# define TX_IF_NULL(a) T_BOOL(a == NULL); (!a) ? exit(42) : ps("")
# define TX_IF(a) {T_BOOL((a)); ((a)) ? exit(42) : ps("");}
# define T_IF(a) T_BOOL((a))
# define CURRENT "Current Line"
# define AT() TEV(__FILE__, __LINE__, __FUNCTION__, CURRENT, i_to_s(__LINE__))
# define NAT() ps("")
# define T(a) TEV(__FILE__, __LINE__, __FUNCTION__, #a, a)
# define TI(a) TEV(__FILE__, __LINE__, __FUNCTION__, #a, i_to_s(a))
# define TC(a) TEV(__FILE__, __LINE__, __FUNCTION__, #a, c_to_s(a))
# define TX(a) T(a); exit(42)
# define TIX(a) TI(a); exit(42)
# define WRONG s_dup("error")
#endif
