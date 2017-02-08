/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 16:28:12 by dan               #+#    #+#             */
/*   Updated: 2016/07/13 21:31:15 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MACRO_H
# define LIBFT_MACRO_H
# define INIT 0
# define BUFF_SIZE 300
# define ISSIGNED(t) (((t)(-1)) < ((t) 0))
# define UMAXOF(t) umaxof(sizeof(t))
# define SMAXOF(t) smaxof(sizeof(t))
# define MAXOF(t) ((ISSIGNED(t)) ? smaxof(sizeof(t)) : umaxof(sizeof(t)))
# define MINOF(t) ((ISSIGNED(t)) ? -(MAXOF(t)) : 0)
# define MINMAX(t) (t_limits){(t)MAXOF(t), (t)MINOF(t)}
#endif
