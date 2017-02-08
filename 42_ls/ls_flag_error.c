/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:42:23 by dan               #+#    #+#             */
/*   Updated: 2016/10/11 17:03:16 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	*flag_error(char flag_attempt)
{
	ps("ls: illegal option -- ");
	ft_printf("%vs", ((char *[]){(char[]){flag_attempt, 0}, "\n", 0}));
	ps("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]");
	ps(" [file ...]\n");
	exit(FLAG_ERROR);
	return (0);
}

void	dir_error(char *dir_attempt)
{
	ft_printf_fd(2, "ls: ");
	ft_printf_fd(2, dir_attempt);
	ft_printf_fd(2, ": No such file or directory\n");
}
