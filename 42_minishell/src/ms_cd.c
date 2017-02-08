/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:30 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 14:32:07 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*ms_cd_arg_str(t_ms_ctx *ctx, char *arg)
{
	if (s_equals(ctx->args[1], "-"))
	{
		s_cpy(arg, ms_env_get_str(ctx->env, "OLDPWD"));
		if (!arg)
		{
			return (0);
		}
	}
	else if (s_equals(ctx->args[1], ".."))
	{
		s_cpy(arg, ms_env_get_str(ctx->env, "PWD"));
		s_cpy(s_tail(arg, 0), "/..");
	}
	else
		s_cpy(arg, ctx->args[1]);
	return (arg);
}

void				ms_cd_home(t_ms_ctx *ctx, char *arg_buff)
{
	char			*try_get;

	try_get = ms_env_get_str(ctx->env, "HOME");
	if (!try_get)
		try_get = getpwuid(getuid())->pw_dir;
	s_cpy(arg_buff, try_get);
}

void				ms_cd_error(char *arg_buff)
{
	int				file_type;

	file_type = ms_is_file(arg_buff);
	if (file_type == MS_UNDEF)
		ft_printf_fd(2, "cd: no such file or directory: %s\n", arg_buff);
	else
		ft_printf_fd(2, "cd: not a directory: %s\n", arg_buff);
}

int					ms_cd(t_ms_ctx *ctx)
{
	char			arg_buff[MS_BUFF_SIZE];
	char			curr_dir[MS_BUFF_SIZE];

	s_clear(arg_buff, MS_BUFF_SIZE);
	if (!ctx->args[1])
		ms_cd_home(ctx, arg_buff);
	else
		ms_cd_arg_str(ctx, arg_buff);
	getcwd(curr_dir, MS_BUFF_SIZE);
	if (!*arg_buff)
	{
		return (0);
	}
	if (chdir(arg_buff) == 0)
	{
		ms_env_xset_val(ctx, "OLDPWD", curr_dir);
		getcwd(arg_buff, MS_BUFF_SIZE);
		ms_env_xset_val(ctx, "PWD", arg_buff);
		ms_set_curr_files(ctx);
	}
	else
	{
		ms_cd_error(arg_buff);
	}
	return (1);
}
