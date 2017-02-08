/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_reduce_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:38 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:47 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				s_clear(char *ln, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		ln[i] = 0;
		i++;
	}
}

char				*ms_reduce_input(t_ms_input *input)
{
	return (lxx_to_s(&input->str_div));
}

void				ms_reduce_line(t_ms_input *input)
{
	ps("\n");
	*input->line = ms_reduce_input(input);
	if (*input->line[0])
		l_push_s(&input->ctx->history, s_dup(*input->line));
}
