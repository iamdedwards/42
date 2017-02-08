/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l_info_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 14:13:08 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 19:49:18 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ls_info_del(t_ls_info **info)
{
	s_del(&(*info)->filename);
	s_del(&(*info)->fullname);
	s_del(&(*info)->sym_link_to);
	s_del(&(*info)->date_modified_str);
	s_del(&(*info)->group_name);
	s_del(&(*info)->user_name);
	s_del(&(*info)->permissions);
	s_del(&(*info)->size_str);
	x_del((void **)info);
}
