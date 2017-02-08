/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format_out.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 13:27:34 by dan               #+#    #+#             */
/*   Updated: 2016/07/12 16:55:18 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FORMAT_OUT_H
# define S_FORMAT_OUT_H
# include "s_format.h"

void		sf_save_padding(t_formatter **f, char c, int n);
void		sf_save_arg(t_formatter **f);
void		sf_save_sign(t_formatter **f, char *s);
int			sf_save_unformatted(t_formatter **f, const char *s, int n);
#endif
