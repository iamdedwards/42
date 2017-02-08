/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:56:08 by dan               #+#    #+#             */
/*   Updated: 2016/08/09 20:16:55 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*permission_map(int n)
{
	static char *map[] = {
		"---",
		"--x",
		"-w-",
		"-wx",
		"r--",
		"r-x",
		"rw-",
		"rwx"
	};

	return (map[n]);
}

static char		*type_map(int n)
{
	static char *map[] = {
		"!",
		"-",
		"d",
		"b",
		"p",
		"l",
		"s"
	};

	if (n > 1)
		n = n / 2;
	return (map[n]);
}

char			*ls_i_forgot_this(char *s, mode_t mode)
{
	if (mode & S_ISUID)
	{
		s[3] = (s[3] == 'x') ? 's' : 'S';
	}
	if (mode & S_ISGID)
	{
		s[6] = (s[6] == 'x') ? 's' : 'S';
	}
	if (mode & S_ISVTX)
	{
		s[9] = (s[9] == 'x') ? 't' : 'T';
	}
	return (s);
}

char			*permission_str(mode_t mode,
				int is_link, int is_acl, int is_attr)
{
	char	rights[14];
	t_list	*ret;
	char	*four_bits;
	int		end;

	buff_val(rights, 0, 14);
	ret = NULL;
	four_bits = i_to_s_base(mode, 8);
	end = s_len(four_bits) - 1;
	if (!is_link)
		l_push_s(&ret, (type_map(four_bits[0] - '0')));
	else
		l_push_s(&ret, (type_map(10)));
	l_push_s(&ret, (permission_map(four_bits[end - 2] - '0')));
	l_push_s(&ret, (permission_map(four_bits[end - 1] - '0')));
	l_push_s(&ret, (permission_map(four_bits[end] - '0')));
	s_del(&four_bits);
	if (is_attr > 0)
		l_push_s(&ret, "@");
	else if (is_acl > 0)
		l_push_s(&ret, "+");
	else
		l_push_s(&ret, " ");
	return (ls_i_forgot_this(lx_to_s(&ret), mode));
}
