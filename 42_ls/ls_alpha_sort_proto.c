/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_alpha_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:00:41 by dan               #+#    #+#             */
/*   Updated: 2016/09/12 14:09:29 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			ls_alpha_sort_base_name_unequal(
					char *sub_curr, char *sub_next)
{
	int				ret;

	ret = 0;
	if (!s_equals(sub_curr, sub_next))
	{
		ret = s_cmp(sub_curr, sub_next);
		if (ret && (ret > 0))
			return (1);
		else if (ret && (ret < 0))
			return (-1);
	}
	return (ret);
}

static int			ls_alpha_sort_space(char *sub_curr, char *sub_next)
{
	int				sub_curr_len;
	int				sub_next_len;

	if (s_equals(sub_curr, sub_next))
		return (0);
	sub_curr_len = s_len(sub_curr);
	sub_next_len = s_len(sub_next);
	if (s_n_equals(sub_curr, sub_next, sub_curr_len))
	{
		if (!s_haschar("_.", sub_next[sub_curr_len])
		&& !c_is_alnum(sub_next[sub_curr_len]))
		{
			return (1);
		}
	}
	if (s_n_equals(sub_next, sub_curr, sub_next_len))
	{
		if (!s_haschar("_.", sub_next[sub_curr_len])
		&& !c_is_alnum(sub_next[sub_curr_len]))
		{
			return (1);
		}
	}
	return (0);
}

static void			set_base_filename(
					t_ls_info *info_curr,
					t_ls_info *info_next, char **curr, char **next)
{
	int				offset_curr;
	int				offset_next;
	int				i;

	i = 0;
	offset_curr = (info_curr->filename[0] == '.');
	offset_next = (info_next->filename[0] == '.');
	while (info_curr->filename[offset_curr] == info_next->filename[offset_next])
	{
		offset_curr++;
		offset_next++;
	}
	*curr = s_sub(&info_curr->filename[offset_curr],
	0, s_nto_c(&info_curr->filename[offset_curr], '.'));
	*next = s_sub(&info_next->filename[offset_next],
	0, s_nto_c(&info_next->filename[offset_next], '.'));
}

static int			ls_alpha_sort_proto_work(
					t_ls_info *info_curr, t_ls_info *info_next)
{
	char			*sub_curr;
	char			*sub_next;
	int				base_len_curr;
	int				base_len_next;
	int				ret;

	set_base_filename(info_curr, info_next, &sub_curr, &sub_next);
	ret = ls_alpha_sort_space(sub_curr, sub_next);
	if (ret)
	{
		s_del(&sub_curr);
		s_del(&sub_next);
		return (ret);
	}
	ret = ls_alpha_sort_base_name_unequal(sub_curr, sub_next);
	s_del(&sub_curr);
	s_del(&sub_next);
	if (ret)
		return (ret);
	sub_curr = s_dup(&info_curr->filename[s_nto_c(info_curr->filename, '.')]);
	sub_next = s_dup(&info_next->filename[s_nto_c(info_next->filename, '.')]);
	ret = (s_cmp(sub_curr, sub_next));
	s_del(&sub_curr);
	s_del(&sub_next);
	return (ret);
}

int					ls_alpha_sort_proto(void *curr, void *next, int rev)
{
	t_ls_info		*info_curr;
	t_ls_info		*info_next;
	int				ret;

	info_curr = (t_ls_info *)curr;
	info_next = (t_ls_info *)next;
	if (!info_next)
		return (-1);
	if ((info_curr->filename)[0] > (info_next->filename)[0])
		return ((rev) ? -1 : 1);
	else if ((info_curr->filename)[0] < (info_next->filename)[0])
		return ((rev) ? 1 : -1);
	ret = ls_alpha_sort_proto_work(info_curr, info_next);
	if (ret > 0)
		return ((rev) ? -1 : 1);
	if (ret < 0)
		return ((rev) ? 1 : -1);
	return (0);
}
