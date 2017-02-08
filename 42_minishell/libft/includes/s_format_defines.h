/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format_defines.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 17:07:02 by dan               #+#    #+#             */
/*   Updated: 2016/07/12 18:59:31 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FORMAT_DEFINES_H
# define S_FORMAT_DEFINES_H
# define SF_SAFE 1
# define SF_SIZELESS -1
# define SF_CHAR 1
# define SF_SHORT 2
# define SF_LONG 3
# define SF_LONGLONG 4
# define SF_SIZET 5
# define SF_INTMAXT 6
# define SF_PARSE_MIN_LEN(a) -a
# define SF_PARSE_MAX_LEN(a) a
# define SF_PARSE_GREEDY 127
#endif
