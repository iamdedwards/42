/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 08:06:37 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/07 13:09:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ms_is_file(char *filename)
{
	struct stat		stats;

	if (!filename || !*filename)
		return (MS_UNDEF);
	if (stat(filename, &stats) == -1)
		return (MS_UNDEF);
	if (S_ISDIR(stats.st_mode))
		return (MS_DIR);
	if (stats.st_mode & S_IXUSR)
		return (MS_CAN_EXEC);
	if (stats.st_mode & S_IXOTH || stats.st_mode & S_IXGRP)
		return (MS_CANT_EXEC);
	if (S_ISREG(stats.st_mode))
		return (MS_FILE);
	TX_IF("wtf");
}
