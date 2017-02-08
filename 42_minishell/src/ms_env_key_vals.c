/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_val_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:31 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 15:50:10 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ms_env_key_vals(t_dictionary *env, char *key,
					t_list **keys, t_list **values)
{
	t_list			*env_keys;
	t_list			*env_values;

	env_keys = env->keys;
	env_values = env->values;
	while (env_keys)
	{
		if (s_equals(env_keys->content, key))
		{
			*keys = env_keys;
			*values = env_values;
			return (1);
		}
		env_keys = env_keys->next;
		env_values = env_values->next;
	}
	*keys = 0;
	*values = 0;
	return (0);
}
