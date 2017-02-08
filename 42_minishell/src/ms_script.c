/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:39 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 11:37:25 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_set_shell_var(t_ms_ctx *ctx, char *ln)
{
	t_list			*split;
	char			*val_prev;
	char			*tmp;

	split = l_dissect(ln, "=");
	if (!split->next)
	{
		l_destroy(&split, x_del);
		return ;
	}
	if (*s_tail(split->content, 1) == '+')
	{
		*s_tail(split->content, 1) = 0;
		val_prev = dict_get_val(ctx->shell_var, split->content);
		if (val_prev)
		{
			tmp = s_join(val_prev, split->next->content);
			x_del(&split->next->content);
			split->next->content = tmp;
		}
	}
	dict_xset_val(&ctx->shell_var, split->content, split->next->content);
	l_destroy(&split, 0);
}

int					s_has_just_trailing_space(char *s)
{
	int				i;
	int				j;

	i = s_len(s) - 1;
	while (s[i] == ' ')
		i--;
	j = 0;
	while (j < i)
	{
		if (s[j] == ' ')
			return (0);
		j++;
	}
	return (1);
}

int					ms_script(t_ms_ctx *ctx, char *ln)
{
	if (s_haschar(ln, '=') && !s_haschar(ln, ' '))
	{
		ms_set_shell_var(ctx, ln);
		return (1);
	}
	return (0);
}
