/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_termios.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:40 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 08:06:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			ms_set_read_params(int on_off)
{
	struct termios	settings;
	static int		vmin_orig = -1;
	static int		vtime_orig = -1;

	tcgetattr(0, &settings);
	if (vmin_orig == -1 && vtime_orig == -1)
	{
		vmin_orig = settings.c_cc[VMIN];
		vtime_orig = settings.c_cc[VTIME];
	}
	if (!on_off)
	{
		settings.c_cc[VMIN] = 1;
		settings.c_cc[VTIME] = 255;
	}
	else
	{
		settings.c_cc[VMIN] = vmin_orig;
		settings.c_cc[VTIME] = vtime_orig;
	}
	tcsetattr(0, TCSANOW, &settings);
}

static void			ms_set_lattr(long clflag, int on_off)
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

void				ms_set_termios(int on_off)
{
	ms_set_lattr(ECHO, on_off);
	ms_set_lattr(ICANON, on_off);
	ms_set_lattr(ISIG, on_off);
	ms_set_read_params(on_off);
}
