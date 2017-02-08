/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:36 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 14:26:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ms_set_input(t_ms_input *input,
					t_ms_ctx *ctx,
					char **line)
{
	*input = (t_ms_input){
		.buff_allocs = 1,
		.height = 0,
		.current_div = 0,
		.str_div = 0,
		.curr_pos = 0,
		.total_len = 0,
		.insert_index = 0,
		.insert_mode = 0,
		.select_mode = 0,
		.select.values = 0,
		.select.value_grids = 0,
		.select.current_value_grid = 0,
		.select.selected = 0,
		.line = line,
		.ctx = ctx,
		.xxkey = 0,
		};
}

char				*ms_get_line(t_ms_ctx *ctx)
{
	t_ms_input		input;
	char			*line;

	ps("\e[s");
	line = NULL;
	ms_set_input(&input, ctx, &line);
	ms_alloc_buff(&input, 0);
	ms_set_termios(0);
	while (!*input.line &&
	!ctx->signals.interrupt &&
	!ctx->signals.eof)
	{
		ms_reader(&input);
	}
	ms_set_termios(1);
	return (*input.line);
}
