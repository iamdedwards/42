/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 19:06:36 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:50 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		rgb_adjust(int n)
{
	if (!n || n < 35)
		return (0);
	if (n > 35 && n < 110)
		return (1);
	if (n > 110 && n < 140)
		return (2);
	if (n > 140 && n < 200)
		return (3);
	if (n > 200 && n < 220)
		return (4);
	return (5);
}

static void		rgb_adjust_all(int *r, int *g, int *b)
{
	*r = rgb_adjust(*r);
	*b = rgb_adjust(*b);
	*g = rgb_adjust(*g);
}

#define IDX_R 0
#define IDX_G 1
#define IDX_B 2

static int		rgb_work(int r, int g, int b)
{
	int		rgb[3];
	int		code;

	rgb_adjust_all(&r, &b, &g);
	rgb[IDX_R] = 0;
	rgb[IDX_G] = 0;
	rgb[IDX_B] = 0;
	while (rgb[IDX_R] < 6)
	{
		while (rgb[IDX_G] < 6)
		{
			while (rgb[IDX_B] < 6)
			{
				code = 16 + ((rgb[IDX_R] * 36) + (rgb[IDX_G] * 6) + rgb[IDX_B]);
				if (r == rgb[IDX_R] && (b == rgb[IDX_B] && g == rgb[IDX_G]))
					return (code);
				rgb[IDX_B]++;
			}
			rgb[IDX_B] = 0;
			rgb[IDX_G]++;
		}
		rgb[IDX_G] = 0;
		rgb[IDX_R]++;
	}
	return (0);
}

char			*sf_rgb_code(int r, int g, int b)
{
	int code;

	code = (rgb_work(r, g, b));
	return (i_to_s(code));
}

void			sf_put_rgb(char *key, int modif)
{
	int				func_len;
	char			*tmp;
	char			*params;
	t_list			*split;

	if (!modif)
		return ;
	func_len = s_inner(key, "(") - key;
	params = s_between(key, "(", ")");
	tmp = s_n_dup(key, func_len);
	if (modif != '\0')
	{
		split = l_split(params, ",");
		if (l_count(split) != 3)
			return ;
		sv_put_n((char *[]){"\e[", (char[]){modif, '\0'}, "8;5;"}, 3);
		ps(sf_rgb_code(s_to_i(split->content),
		s_to_i(l_goto(split, 1)->content),
		s_to_i(l_goto(split, 2)->content)));
		pc('m');
	}
}
