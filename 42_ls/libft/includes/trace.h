/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:43:12 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/25 19:32:46 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H
# ifndef NOTRACE
#  define LOGFUNC ft_printf
#  define TCV(a, b, c) LOGFUNC("[%s]:%s[%d]%s%s", a, "\e[31m", b, "\e[0m", c)
#  define TC(a, b, c) TCV(a, b, c)
#  define TEVEV(a, b) LOGFUNC(" \e[33m%s = \e[0m%s\n",  a, b)
#  define TEV(a, b, c, d, e) TC(a, b, c); TEVEV(d, e)
# else
#  define TEV(a, b, c, d, e) ps("");
# endif
# define LOGC(a) LOGFUNC("%c", a); AT()
# define OUT(a) LOGFUNC("%s", a); AT()
# define OUT(a) LOGFUNC("%s", a); AT()
# define PUT_BOOL(a) LOGFUNC("%s is %s\n", #a, (a == 1) ? "TRUE" : "FALSE");
# define CURRENT "Current Line"
# define AT() TEV(__FILE__, __LINE__, __FUNCTION__, CURRENT, i_to_s(__LINE__))
# define NAT() ps("")
# define T(a) TEV(__FILE__, __LINE__, __FUNCTION__, #a, a)
# define TI(a) TEV(__FILE__, __LINE__, __FUNCTION__, #a, i_to_s(a))
# define TX(a) T(a); exit(42)
# define TXF(a) TX(__FUNCTION__)
# define TIX(a) TI(a); exit(42)
# define WRONG s_dup("error")
# define TLOOP() static int _itr_ = 0; TI(_itr_); _itr_++
# ifndef EXIT_AT
#  define EXIT_AT 1
# endif
#endif
