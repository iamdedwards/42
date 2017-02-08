/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:31 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 13:18:25 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_cmd_error(t_ms_ctx *ctx, char *file)
{
	int				file_type;
	char			*try_get;
	char			*abs_path;

	abs_path = NULL;
	if ((try_get = ms_env_get_str(ctx->env, "PWD")))
	{
		abs_path = sv_join((char *[]){try_get, "/", file, 0});
		file_type = ms_is_file(abs_path);
		s_del(&abs_path);
	}
	else
		file_type = ms_is_file(file);
	if (file_type != MS_UNDEF && s_n_equals(file, "./", 2))
		ft_printf("minishell: permission denied: ");
	else
		ft_printf("minishell: unknown command: ");
	ft_printf("%s\n", file);
	exit(0);
}

int					ms_execute_cwd(t_ms_ctx *ctx)
{
	ms_set_shlvl(ctx, 1);
	if (ms_is_file(ctx->args[0]) == MS_CAN_EXEC)
	{
		if (execve(ctx->args[0], &ctx->args[0], ctx->env_as_sv) != -1)
		{
			return (1);
		}
	}
	ms_set_shlvl(ctx, -1);
	return (0);
}

void				ms_execute_with_path(t_ms_ctx *ctx)
{
	t_list			*paths;
	int				do_ret;
	char			*cmd_buff;

	if (ms_is_minishell_exec(ctx))
		ms_set_shlvl(ctx, 1);
	if (ms_execute_cwd(ctx))
		return ;
	paths = ms_env_get_list(ctx->env, "PATH");
	if (!paths)
		ms_cmd_error(ctx, ctx->args[0]);
	do_ret = 1;
	while (paths && do_ret)
	{
		if (!s_n_equals(ctx->args[0], paths->content, s_len(paths->content)))
			cmd_buff = s_format("{s}/{s}", paths->content, ctx->args[0]);
		else
			cmd_buff = s_dup(ctx->args[0]);
		if (ms_is_file(cmd_buff) == MS_CAN_EXEC)
			do_ret = (execve(cmd_buff, &ctx->args[0], ctx->env_as_sv)) == -1;
		s_del(&cmd_buff);
		paths = paths->next;
	}
	ms_set_shlvl(ctx, -1);
	ms_cmd_error(ctx, ctx->args[0]);
}

int					ms_execute(t_ms_ctx *ctx)
{
	pid_t			pid;
	int				status;
	int				do_ret;

	pid = fork();
	if (pid == 0)
	{
		ms_execute_with_path(ctx);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do_ret = 1;
		while (do_ret)
		{
			waitpid(pid, &status, WUNTRACED);
			do_ret = (!WIFEXITED(status) && !WIFSIGNALED(status));
			if (WIFSIGNALED(status))
				ps("\n");
		}
	}
	return (1);
}
