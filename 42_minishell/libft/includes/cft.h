/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cft.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 14:55:03 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/28 12:18:54 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CFT_H
# define CFT_H

char					*c_to_s(int c);
int						c_is_alnum(int c);
int						c_is_non_alnum(int c);
int						c_is_alpha(int c);
int						c_is_ascii(int c);
int						c_is_digit(int c);
int						c_is_lower(int c);
int						c_is_print(int c);
int						c_is_upper(int c);
int						c_to_lower(int c);
int						c_to_upper(int c);
#endif
