/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_exec_rights.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:17:44 by dedwards          #+#    #+#             */
/*   Updated: 2016/11/02 20:18:14 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int					main(void)
{
	write(1, "KO\n", 3);
}