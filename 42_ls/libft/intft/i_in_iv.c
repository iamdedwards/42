/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_in_iv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dedwards@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 14:14:42 by dan               #+#    #+#             */
/*   Updated: 2016/06/30 21:51:43 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	i_in_iv(int *i_ref, int search, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (i_ref[i++] == search)
		{
			return (1);
		}
	}
	return (0);
}