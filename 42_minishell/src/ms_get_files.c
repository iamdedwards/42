/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:35 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 18:09:14 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			l_contains_s(t_list *x, char *s)
{
	while (x)
	{
		if (s_equals(x->content, s))
			return (1);
		x = x->next;
	}
	return (0);
}

int					ms_alpha_sort(void *curr, void *next)
{
	int				ret;

	ret = s_cmp(curr, next);
	if (ret != 0)
	{
		ret = (ret > 0) ? 1 : -1;
	}
	return (ret);
}

static void			ms_push_file(t_list **l, char *name)
{
	struct stat		file_stat;

	stat(name, &file_stat);
	if (!l_contains_s(*l, name))
	{
		l_push_sort_content(l,
		l_new(s_dup(name), file_stat.st_mode), ms_alpha_sort);
	}
}

void				ms_set_curr_files(t_ms_ctx *ctx)
{
	DIR				*dir_ptr;
	struct dirent	*entry;
	char			*dir_name;
	char			curr_dir[2048];

	dir_name = getcwd(curr_dir, 2048);
	if (ctx->curr_files)
		l_destroy(&ctx->curr_files, x_del);
	dir_ptr = opendir(dir_name);
	if (dir_ptr)
	{
		while ((entry = readdir(dir_ptr)) != NULL)
		{
			if ('.' != entry->d_name[0])
			{
				ms_push_file(&ctx->curr_files, entry->d_name);
			}
		}
		closedir(dir_ptr);
	}
}

void				ms_set_binary_files(t_ms_ctx *ctx)
{
	struct dirent	*entry;
	DIR				*dir_ptr;
	t_list			*paths;

	if (ctx->curr_files)
		l_destroy(&ctx->binary_files, x_del);
	paths = ms_env_get_list(ctx->env, "PATH");
	while (paths)
	{
		dir_ptr = opendir(paths->content);
		if (dir_ptr)
		{
			while ((entry = readdir(dir_ptr)) != NULL)
			{
				if ('.' != entry->d_name[0])
				{
					ms_push_file(&ctx->binary_files, entry->d_name);
				}
			}
			closedir(dir_ptr);
		}
		paths = paths->next;
	}
}
