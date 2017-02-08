/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_binary_exists.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:35:03 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 14:35:04 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ms_binary_exists(t_ms_ctx *ctx, char *filename)
{
	t_list			*run;

	run = ctx->binary_files;
	while (run)
	{
		if (s_equals(filename, run->content))
			return (1);
		run = run->next;
	}
	return (0);
}
