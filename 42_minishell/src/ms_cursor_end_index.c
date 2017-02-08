/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cursor_end_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:30 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:07:54 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ms_cursor_end_index(t_ms_input *input)
{
	int				pwd_len;
	t_list			*pwd_split;
	char			cwd[MS_BUFF_SIZE];

	pwd_split = ms_env_get_list(input->ctx->env, "PWD_SPLIT");
	if (!pwd_split)
	{
		getcwd(cwd, MS_BUFF_SIZE);
		return (s_len(cwd) + 8);
	}
	pwd_len = s_len(l_last(pwd_split)->content);
	return (pwd_len + 8);
}
