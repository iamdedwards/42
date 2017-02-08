/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:29 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:42 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			*dict_get_val(t_dictionary env_dict, char *key)
{
	int				i;

	i = 0;
	while (env_dict.keys)
	{
		if (s_equals(env_dict.keys->content, key))
		{
			return (l_goto(env_dict.values, i)->content);
		}
		env_dict.keys = env_dict.keys->next;
		i++;
	}
	return (0);
}

void			dict_xset_val(t_dictionary *env_dict, char *key, void *val)
{
	int				i;
	t_list			*env_dict_keys;
	t_list			*env_dict_values;
	void			*content;

	env_dict_keys = env_dict->keys;
	env_dict_values = env_dict->values;
	i = 0;
	while (env_dict_keys)
	{
		if (s_equals(env_dict_keys->content, key))
		{
			content = l_goto(env_dict_values, i)->content;
			x_del(&content);
			l_goto(env_dict_values, i)->content = val;
			return ;
		}
		env_dict_keys = env_dict_keys->next;
		i++;
	}
	l_push(&env_dict->keys, l_new_s(key));
	l_push(&env_dict->values, l_new(val, *key));
}

void			dict_set_val(t_dictionary *env_dict, char *key, void *val)
{
	int				i;
	t_list			*env_dict_keys;
	t_list			*env_dict_values;

	env_dict_keys = env_dict->keys;
	env_dict_values = env_dict->values;
	i = 0;
	while (env_dict_keys)
	{
		if (s_equals(env_dict_keys->content, key))
		{
			l_goto(env_dict_values, i)->content = val;
			return ;
		}
		env_dict_keys = env_dict_keys->next;
		i++;
	}
	l_push(&env_dict->keys, l_new_s(key));
	l_push(&env_dict->values, l_new(val, *key));
}

t_dictionary	dict_init(void ***vals)
{
	int				i;
	t_dictionary	dict;

	dict.keys = 0;
	dict.values = 0;
	i = 0;
	while (vals[i])
	{
		l_push_s(&dict.keys, vals[i][0]);
		l_push(&dict.values, l_new(vals[i][1], *(char *)vals[i][0]));
		i++;
	}
	return (dict);
}
