/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_insert_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:36 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 13:00:38 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ms_var_len(char *s)
{
	int				i;

	i = 0;
	while (s[i] && c_is_alpha(s[i]) && s[i] != ' ')
	{
		i++;
	}
	return (i);
}

void				ms_xset_str_to_var(t_ms_ctx *ctx, char **s)
{
	char			*try_get;
	t_list			*try_get_lst;

	try_get_lst = NULL;
	try_get = NULL;
	if (*s)
	{
		try_get_lst = ms_env_get_list(ctx->env, *s);
		if (try_get_lst)
			try_get = l_to_s(try_get_lst);
		else
		{
			try_get = dict_get_val(ctx->shell_var, *s);
			if (try_get)
			{
				try_get = s_dup(try_get);
			}
		}
	}
	s_del(s);
	if (try_get)
		*s = try_get;
	else
		*s = s_dup("");
}

char				*ms_insert_var_ret(t_list **split)
{
	int				len;
	char			*s;
	t_list			*run;

	run = *split;
	len = 0;
	while (run)
	{
		len += s_len(run->content);
		run = run->next;
	}
	run = *split;
	s = s_new(len);
	while ((run))
	{
		if (run->content && !s_equals(run->content, "$"))
		{
			s_cpy(&s[s_len(s)], (run)->content);
		}
		(run) = (run)->next;
	}
	l_destroy(split, x_del);
	return (s);
}

void				ms_insert_home(t_ms_ctx *ctx, char **s)
{
	char			*try_get;
	char			arg[1024];
	t_list			*split;
	t_list			*run;

	try_get = ms_env_get_str(ctx->env, "HOME");
	if (!try_get)
		try_get = getpwuid(getuid())->pw_dir;
	s_cpy(arg, try_get);
	split = l_split(*s, "~");
	run = split;
	while (run)
	{
		if (s_equals(run->content, "~"))
		{
			s_del((char **)&run->content);
			run->content = s_dup(arg);
		}
		run = run->next;
	}
	s_del(s);
	*s = lxx_to_s(&split);
}

void				ms_insert_var(t_ms_ctx *ctx, char **ln)
{
	t_list			*split;
	t_list			*run;

	if (!*ln || (!s_inner(*ln, "$") && !s_inner(*ln, "~")))
		return ;
	if (s_haschar(*ln, '~'))
	{
		ms_insert_home(ctx, ln);
	}
	split = l_split(*ln, "$");
	run = split;
	while (run)
	{
		if (run && run->next)
		{
			if (s_equals(run->content, "$"))
			{
				if (run->next->content)
					ms_xset_str_to_var(ctx, (char **)&run->next->content);
			}
		}
		run = run->next;
	}
	s_del(ln);
	*ln = ms_insert_var_ret(&split);
}
