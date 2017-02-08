/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 15:37:13 by dedwards          #+#    #+#             */
/*   Updated: 2016/09/30 21:06:07 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*l_new(void const *content, size_t index)
{
	t_list			*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = (void *)content;
	new->index = index;
	new->next = NULL;
	return (new);
}

t_list				*l_new_l(t_list *l)
{
	return (l_new(l, sizeof(t_list)));
}

t_list				*l_new_i(int i)
{
	int				*ref;

	ref = (int *)malloc(sizeof(int));
	*ref = i;
	return (l_new(ref, sizeof(int)));
}

t_list				*l_new_f(float f)
{
	return (l_new(f_alloc(f), sizeof(float)));
}

t_list				*l_new_s(char *content)
{
	return (l_new(content, sizeof(char)));
}
