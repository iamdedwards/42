/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_cols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:34 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:08:51 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ms_vertical_pos(void)
{
	char			buff[20];
	t_list			*split;
	int				ret;

	ps("\e[6n");
	read(0, buff, 10);
	split = l_dissect(&buff[2], ";");
	ret = s_to_i(split->content);
	l_destroy(&split, x_del);
	return (ret);
}

int					ms_get_cols(void)
{
	struct winsize	term_size;
	int				size;

	ioctl(0, TIOCGWINSZ, &term_size);
	size = (term_size.ws_col);
	return (size);
}
