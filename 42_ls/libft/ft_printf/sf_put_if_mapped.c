/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_direct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 20:14:48 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:50 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				put_if_mapped(char *key, char modif, t_s_s_map *map, char flag)
{
	char			*code;

	if ((code = s_s_map_value(map, key)))
	{
		ps("\e[");
		if (modif)
			pc(modif);
		ps(code);
		pc(flag);
		return (1);
	}
	return (0);
}

void			put_func_if_mapped(char *key)
{
	int				func_len;
	char			*tmp;
	int				arg;
	char			*params;

	func_len = s_inner(key, "(") - key;
	params = s_between(key, "(", ")");
	tmp = s_n_dup(key, func_len);
	if (!s_equals(tmp, "rgb"))
	{
		if (s_haschar(params, ','))
		{
			params[s_nto_c(params, ',')] = ';';
			if (s_haschar(params, ' '))
				s_move(s_inner(params, " "), 1);
		}
		arg = pf_move_map(tmp);
		if (arg == 'K')
			stall(s_to_i(params));
		sv_put_n((char *[]){"\e[", (params) ? params : "1" }, 2);
		pc(arg);
	}
	s_del(&tmp);
	s_del(&params);
}
