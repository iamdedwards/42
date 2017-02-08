/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 16:32:29 by dan               #+#    #+#             */
/*   Updated: 2016/08/05 15:54:56 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPFT_H
# define MAPFT_H

typedef int		(*t_map_val_getter)(void *, void *);
typedef struct	s_oo_map
{
	void		*key;
	void		*value;
}				t_oo_map;

typedef struct	s_section
{
	int			start;
	int			end;

}				t_section;

typedef struct	s_s_c_map
{
	char		*key;
	char		value;
}				t_s_c_map;

typedef struct	s_ss_map
{
	char		*key;
	char		*value;
}				t_s_s_map;

typedef struct	s_s_i_map
{
	char		*key;
	int			value;
}				t_s_i_map;

typedef	struct	s_sv_s_map
{
	char		*key;
	char		**values;
}				t_sv_s_map;

typedef struct	s_i_s_map
{
	int			key;
	char		*value;
}				t_i_s_map;

typedef struct	s_s_o_map
{
	char		*key;
	void		*value;
}				t_s_o_map;

char			*s_s_map_value(t_s_s_map *map, char *key);
void			*oo_map_getval(t_oo_map *map, void *key, t_map_val_getter gtr);
void			oo_map_del(void **vmap);
#endif
