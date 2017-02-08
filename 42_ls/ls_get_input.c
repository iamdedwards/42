/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:10:33 by dedwards          #+#    #+#             */
/*   Updated: 2016/10/03 12:50:16 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			find_flag_errors(char *elem)
{
	char			test_char;
	char			apology_char;

	test_char = 0;
	if (s_len(elem) == 1 && elem[0] == '-')
		return (0);
	if ((test_char = s_has_other_than(elem,
	"NABCDFGHLOPRSTUWabcdefghijklmnopqrstuwx1")))
	{
		flag_error(test_char);
	}
	if ((apology_char = s_has_other_than(elem, "NlartR1A")))
	{
		ft_printf("ls: unimplemented option -- %c\n", apology_char);
	}
	return (test_char);
}

static t_list		*is_ls_flag(t_list *elem)
{
	int				test_char;
	static int		end_flags = 0;

	if (!elem || end_flags)
	{
		return (NULL);
	}
	if ((L_STR(elem)[0] != '-'))
		end_flags = 1;
	if ((L_STR(elem)[0] && L_STR(elem)[0] == '-') && (L_STR(elem)[1]))
	{
		if (!find_flag_errors(&elem->content[1]))
		{
			if (s_equals(elem->content, "--"))
				end_flags = 1;
			return (l_new_s(elem->content));
		}
	}
	return (NULL);
}

static t_list		*is_dir(t_list *elem)
{
	DIR				*dir_ptr;
	struct stat		stats;
	int				device;
	char			*tmp;

	dir_ptr = opendir(elem->content);
	if (!dir_ptr)
	{
		return (l_new(elem->content, LS_UNKNOWN));
	}
	else
	{
		closedir(dir_ptr);
		return (l_new_s(elem->content));
	}
}

t_list				*get_dirs(t_list *lav)
{
	t_list			*outdirs;

	if (lav)
	{
		outdirs = l_filter(lav, is_dir);
		return (outdirs);
	}
	return (NULL);
}

t_list				*get_flags(t_list *lav)
{
	t_list			*outflags;

	if (lav)
	{
		outflags = l_filter(lav, is_ls_flag);
		return (outflags);
	}
	return (NULL);
}
