/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ws_to_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:23:24 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/25 17:13:46 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		s_11_bit_unicode_buff(char *buff, wchar_t wc)
{
	buff[0] = (unsigned char)((wc >> 6) | 0xC0);
	buff[1] = (unsigned char)((wc & 0x3F) | 0x80);
}

static void		s_16_bit_unicode_buff(char *buff, wchar_t wc)
{
	buff[0] = (unsigned char)(((wc >> 12)) | 0xE0);
	buff[1] = (unsigned char)(((wc >> 6) & 0x3F) | 0x80);
	buff[2] = (unsigned char)((wc & 0x3F) | 0x80);
}

static void		s_21_bit_unicode_buff(char *b, wchar_t wc)
{
	b[0] = (unsigned char)(((wc >> 18)) | 0xF0);
	b[1] = (unsigned char)(((wc >> 12) & 0x3F) | 0x80);
	b[2] = (unsigned char)(((wc >> 6) & 0x3F) | 0x80);
	b[3] = (unsigned char)((wc & 0x3F) | 0x80);
}

char			*unicode_to_utf8(wchar_t wc)
{
	char			buff[5];

	buff_val(buff, 0, 5);
	if (wc < (1 << 7))
	{
		buff[0] = (unsigned char)(wc);
	}
	else if (wc < (1 << 11))
	{
		s_11_bit_unicode_buff(buff, wc);
	}
	else if (wc < (1 << 16))
	{
		s_16_bit_unicode_buff(buff, wc);
	}
	else if (wc < (1 << 21))
	{
		s_21_bit_unicode_buff(buff, wc);
	}
	return (s_dup(buff));
}

char			*ws_to_s(wchar_t *ws)
{
	int				i;
	t_list			*ret;

	ret = NULL;
	i = 0;
	while (ws[i])
	{
		l_push(&ret, l_new_s(unicode_to_utf8(ws[i])));
		i++;
	}
	return (lxx_to_s(&ret));
}
