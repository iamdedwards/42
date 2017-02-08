/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_month.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 19:01:37 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/19 14:46:31 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			ls_put_year(char *date_str,
					char *year_str, long today_ticks)
{
	int				put_year;

	put_year = !s_equals(year_str, s_tail(ctime(&today_ticks), 5));
	if (!put_year)
	{
		put_year = month(date_str) - month(&ctime(&today_ticks)[4]);
		put_year = (put_year < 0) ? -put_year : put_year;
		if (put_year == 6)
		{
			put_year = s_n_to_i(&ctime(&today_ticks)[8], 2) -
			s_n_to_i(&date_str[4], 2) >= 0;
		}
		else
			put_year = (put_year > 6);
	}
	return (put_year);
}

void				ls_set_date(char **date_str_p, long date_ticks)
{
	char			*date_str;
	char			*year_str;
	int				put_year;
	long			today_ticks;

	today_ticks = time(0);
	date_str = s_dup(&(ctime(&date_ticks)[4]));
	year_str = s_tail(date_str, 5);
	put_year = ls_put_year(date_str, year_str, today_ticks);
	if (!put_year)
		s_tail(date_str, 9)[0] = 0;
	else
	{
		s_n_cpy(s_tail(date_str, 13), year_str, 4);
		date_str[7] = ' ';
		date_str[12] = 0;
	}
	*date_str_p = date_str;
}
