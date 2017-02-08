/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_cols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 13:20:53 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/19 14:44:38 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t				ls_get_cols(void)
{
	struct winsize	term_size;

	ioctl(0, TIOCGWINSZ, &term_size);
	return (term_size.ws_col - ((term_size.ws_col / 100) * 25) - 16);
}
