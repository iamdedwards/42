/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 11:43:12 by dedwards          #+#    #+#             */
/*   Updated: 2016/09/29 13:09:19 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "../includes/s_format.h"
# define PUT_LINE ft_printf("{red;white}line:%d", __LINE__)
# define PUT_FUNC ft_printf("{white;black}%s()", __FUNCTION__)
# define PUT_FILE ft_printf("{black;yellow}[%s]", __FILE__)
# define PUT_TRACE PUT_FILE; PUT_FUNC; PUT_FILE;
# define ERROR(a) ft_printf("ERROR: -=={%s}==-", #a); PUT_TRACE; exit(-1)
# define ERROR_IF(a) if (a) { ERROR(a); }

int					put_error(int erno, char *msg);
#endif
