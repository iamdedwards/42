/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_save.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 17:44:21 by dan               #+#    #+#             */
/*   Updated: 2016/07/13 15:16:14 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SF_SAVE_H
# define SF_SAVE_H
# include "s_format.h"

void			sf_save_padding(t_formatter **f, char c, int n);
void			sf_save_arg(t_formatter **f);
void			sf_save_sign(t_formatter **f, char *s);
int				sf_s(t_formatter **f);
int				sf_c(t_formatter **f);
int				sf_save_unformatted(t_formatter **f, const char *s, int n);
#endif
