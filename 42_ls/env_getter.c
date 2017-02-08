/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:35:15 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/26 16:47:42 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*get_env_var(t_list *env_lst, char *key)
{
	char			*value;

	while (env_lst)
	{
		value =
		oo_map_getval(env_lst->content, key, (t_map_val_getter)s_equals);
		if (value)
			return (value);
		env_lst = env_lst->next;
	}
	return (0);
}

t_list				*l_init_env(char **env)
{
	t_list			*ret;
	int				i;
	t_s_s_map		*map;
	t_list			*split;

	i = 0;
	ret = NULL;
	while (env[i])
	{
		map = (t_s_s_map *)malloc(sizeof(t_s_s_map));
		*map = (t_s_s_map)
		{
			s_n_dup(env[i], s_nto_c(env[i], '=')),
			s_dup(&env[i][s_nto_c(env[i], '=') + 1])
		};
		l_push(&ret, l_new(map, sizeof(t_s_s_map)));
		i++;
	}
	return (ret);
}
