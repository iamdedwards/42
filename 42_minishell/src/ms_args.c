/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:29 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 13:01:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ms_args_rem_subs_space_work(char **arg, int i)
{
	if ((*arg)[i] == 26)
		(*arg)[i] = ' ';
	if ((*arg)[i] == '\"')
	{
		if (i == 0 || (*arg)[i - 1] != '\\')
		{
			while ((*arg)[i] == '\"')
				s_move(&(*arg)[i], 1);
		}
		else if ((*arg)[i - 1] == '\\')
			s_move(&(*arg)[i - 1], 1);
	}
}

t_list			*ms_args_rem_subs_space(t_ms_ctx *ctx, char *s)
{
	t_list			*ret;
	t_list			*run;
	int				i;
	char			*arg;

	ret = l_dissect(s, " ");
	run = ret;
	while (run)
	{
		i = 0;
		arg = run->content;
		while (arg[i])
		{
			ms_args_rem_subs_space_work(&arg, i);
			i++;
		}
		if (arg[0] != '\"')
		{
			ms_insert_var(ctx, (char **)&run->content);
		}
		run = run->next;
	}
	return (ret);
}

char			**ms_args(t_ms_ctx *ctx, char *s)
{
	int				i;
	int				on;
	t_list			*ret;

	i = 0;
	on = 0;
	while (s[i])
	{
		if (on && s[i] == '\"' && (i > 0) && s[i - 1] != '\\')
			on = 0;
		else if (!on && s[i] == '\"' && (i > 0) && s[i - 1] != '\\')
			on = 1;
		else if (on && s[i] == ' ')
			s[i] = 26;
		i++;
	}
	if (on)
	{
		ft_printf_fd(2, "minishell: unescaped [\"]\n");
		return (0);
	}
	ret = (ms_args_rem_subs_space(ctx, s));
	return (lx_to_sv(&ret));
}
