/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 11:35:55 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/01 17:01:43 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			join_till_nl(t_list **store, t_list *split)
{
	char			*was;
	char			*is;

	was = l_last(*store)->content;
	is = s_join(was, split->content);
	free(was);
	l_last(*store)->content = is;
}

static int			attr_line(t_list **store, char **line)
{
	t_list			*hold;

	*line = (*store)->content;
	s_tail(*line, 1)[0] = 0;
	hold = *store;
	*store = (*store)->next;
	free(hold);
	return (1);
}

static int			read_lines(int fd, char **line, t_list **store)
{
	int				ret;
	char			buff[BUFF_SIZE];
	t_list			*split;

	*line = 0;
	if (*store && s_haschar((*store)->content, '\n'))
		return (attr_line(store, line));
	ret = read(fd, buff, BUFF_SIZE - 1);
	if (ret <= 0)
		return (ret);
	buff[ret] = 0;
	split = l_dissect(buff, "\n");
	if (*store && !s_haschar(l_last(*store)->content, '\n'))
	{
		join_till_nl(store, split);
		split = split->next;
	}
	if (split)
		l_push(store, split);
	if (!s_haschar((*store)->content, '\n'))
		return (read_lines(fd, line, store));
	return (attr_line(store, line));
}

int					io_using(int fd, char **line, int mode)
{
	static t_list	*base[MULTI_FD] = {0};

	if (fd == -1)
		return (-1);
	if (mode == GNL_READ)
	{
		return (read_lines(fd, line, &base[fd]));
	}
	else if (mode == GNL_DISPOSE)
		l_destroy(&base[fd], x_del);
	return (1);
}
