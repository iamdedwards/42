/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_reader_signal_handlers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:38 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:47 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_sig_interupt(t_ms_input *input)
{
	input->ctx->signals.interrupt = 1;
	ms_erase_put(input, 0);
	ps("\n");
}

void				ms_sig_eof(t_ms_input *input)
{
	input->ctx->signals.eof = 1;
	ms_destroy_input(input);
	ms_destroy_ctx(input->ctx);
}
