/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 13:59:19 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/14 14:13:35 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*l_init_iv(int *array, size_t size)
{
	t_list			*alst;

	alst = NULL;
	while (size--)
	{
		l_add(&alst, l_new_i(array[size]));
	}
	return (alst);
}

t_list			*l_init_sv(char **array)
{
	t_list			*alst;
	int				i;

	i = 0;
	alst = NULL;
	while (array[i])
	{
		l_push(&alst, l_new_s(s_dup(array[i++])));
	}
	return (alst);
}

t_list			*l_init_fv(float *array, size_t size)
{
	t_list			*alst;

	alst = NULL;
	while (size--)
	{
		l_push(&alst, l_new_f((array[size])));
	}
	return (alst);
}
