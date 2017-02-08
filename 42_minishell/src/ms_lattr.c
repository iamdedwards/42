/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lattr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:37 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:46 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ms_set_lattr(long clflag, int on_off)
{
	struct termios	settings;

	if (on_off == 1)
	{
		tcgetattr(0, &settings);
		settings.c_lflag |= clflag;
		tcsetattr(0, TCSANOW, &settings);
	}
	if (on_off == 0)
	{
		tcgetattr(0, &settings);
		settings.c_lflag &= ~clflag;
		tcsetattr(0, TCSANOW, &settings);
	}
}

int					ms_get_lattr(long clflag)
{
	tcflag_t			ret;
	struct termios		settings;

	tcgetattr(0, &settings);
	ret = settings.c_lflag;
	ret &= ~clflag;
	if (ret == settings.c_lflag)
		return (0);
	return (1);
}
