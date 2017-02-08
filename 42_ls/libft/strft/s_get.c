/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_get.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:54 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:24:55 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_from_buffer(t_gnl **body, char ***line, int bytes,
		char *splitter)
{
	int				size;
	char			**split;
	int				i;

	if ((*body)->buffer && (s_len((*body)->buffer) != 0) &&
		(((size = ft_nsbtws((*body)->buffer, splitter)) > 1) ||
		(((*body)->fd == 0) || bytes == 0)))
	{
		i = 0;
		split = ft_sssplit((*body)->buffer, splitter);
		**line = split[i++];
		if ((*body)->fd == 0)
			free(split[1]);
		while ((*body)->fd != 0 && (i <= size - (!(bytes == 0))))
		{
			if (split[i] != NULL)
				l_push(&(*body)->lines, l_new(split[i], 0));
			i++;
		}
		free((*body)->buffer);
		(*body)->buffer = ((bytes == 0) || (*body)->fd) == 0 ?
		s_dup("\0") : split[size];
		return (1);
	}
	return (0);
}

static int			get_lines(t_gnl **body, char ***line, char *splitter)
{
	t_list			*clean;
	t_list			*nl;

	nl = NULL;
	if ((*body) && (*body)->lines)
	{
		if (s_cmp((char *)((*body)->lines->content), splitter) == 0)
		{
			nl = (*body)->lines;
			(*body)->lines = (*body)->lines->next;
			free(nl);
		}
		**line = (char *)(*body)->lines->content;
		clean = (*body)->lines;
		(*body)->lines = (*body)->lines->next;
		free(clean);
		clean = NULL;
		nl = NULL;
		return (1);
	}
	return (0);
}

static t_gnl		*init_gnl(int fd)
{
	t_gnl *gnl;

	gnl = (t_gnl *)malloc(sizeof(t_gnl));
	gnl->lines = NULL;
	gnl->buffer = s_dup("\0");
	gnl->fd = fd;
	gnl->tmp = NULL;
	gnl->next = NULL;
	return (gnl);
}

static t_gnl		*get_body(t_gnl **head, int fd, t_gnl **follower)
{
	t_gnl *runner;
	t_gnl *new_one;

	if ((*head)->fd == fd)
	{
		return ((*head));
	}
	runner = (*head);
	while (runner->next)
	{
		if (runner->next->fd == fd)
			*follower = runner;
		runner = runner->next;
		if (runner->fd == fd)
			return (runner);
	}
	new_one = init_gnl(fd);
	*follower = runner;
	runner->next = new_one;
	return (new_one);
}

int					s_get(int fd, char **line, char *splitter)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static t_gnl	*head = NULL;
	t_gnl			*body;
	t_gnl			*cleaner;

	head = (!head) ? init_gnl(0) : head;
	body = get_body(&head, fd, &cleaner);
	if (fd != 0 && get_lines(&body, &line, splitter))
		return (1);
	if (get_from_buffer(&body, &line, 1, splitter))
		return (1);
	if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[(ret != -1) ? ret : 0] = 0;
		body->tmp = s_join(body->buffer, buff);
		free(body->buffer);
		body->buffer = body->tmp;
		return (get_next_line(fd, line));
	}
	ret = (ret == -1) ? -1 : get_from_buffer(&body, &line, ret, splitter);
	cleaner->next = (cleaner->next->next) ? cleaner->next->next : NULL;
	s_del(&body->buffer);
	free(body);
	return (ret);
}
