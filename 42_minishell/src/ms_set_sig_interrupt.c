/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_sig_interrupt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:39 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_set_sig_interrupt(int n)
{
	(void)n;
	ms_get_ctx()->signals.interrupt = 1;
}
