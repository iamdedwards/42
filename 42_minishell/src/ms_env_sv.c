/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_sv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:31 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:44 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			each_s_len(t_list *a)
{
	int				len;

	len = 0;
	while (a)
	{
		len += s_len(a->content);
		a = a->next;
	}
	return (len);
}

static char			*ms_reduce_str(t_list *run)
{
	int				len;
	char			*s;

	len = each_s_len(run) + l_count(run);
	s = s_new(len);
	while ((run))
	{
		s_cpy(&s[s_len(s)], (run)->content);
		if (run->next)
			s_cpy(&s[s_len(s)], ":");
		(run) = (run)->next;
	}
	return (s);
}

char				**ms_env_sv(t_dictionary dict)
{
	char			**env;
	int				i;
	int				len;
	char			*tmp;

	i = 0;
	len = l_count(dict.values) + 1;
	env = (char **)malloc(sizeof(char *) * len);
	while (dict.values)
	{
		tmp = ms_reduce_str(dict.values->content);
		env[i] = s_format("{s}={s}",
			dict.keys->content,
			tmp);
		s_del(&tmp);
		dict.values = dict.values->next;
		dict.keys = dict.keys->next;
		i++;
	}
	env[i] = 0;
	return (env);
}
