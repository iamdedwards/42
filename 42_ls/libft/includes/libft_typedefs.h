/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_typedefs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 21:35:34 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/13 21:37:35 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPEDEFS_H
# define LIBFT_TYPEDEFS_H
# include "libft.h"

typedef struct			s_list
{
	void				*content;
	size_t				index;
	struct s_list		*next;
}						t_list;

typedef struct			s_gnl
{
	t_list				*lines;
	char				*buffer;
	char				*tmp;
	int					fd;
	struct s_gnl		*next;
}						t_gnl;

typedef struct			s_map
{
	t_list				*key;
	t_list				*value;
}						t_map;

typedef struct			s_limits
{
	unsigned long long	max;
	long long			min;
}						t_limits;

typedef struct			s_int_to_s_info
{
	t_limits			limits;
	unsigned int		base;

}						t_int_to_s_info;

#endif
