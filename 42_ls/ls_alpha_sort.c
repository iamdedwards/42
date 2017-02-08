/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_alpha_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 18:08:18 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/28 16:50:10 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ls_alpha_sort(void *curr, void *next)
{
	return (ls_alpha_sort_proto(curr, next, 0));
}

int					ls_alpha_sort_rev(void *curr, void *next)
{
	return (ls_alpha_sort_proto(curr, next, 1));
}
