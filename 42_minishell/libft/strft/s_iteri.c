/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_iteri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:54 by dedwards          #+#    #+#             */
/*   Updated: 2016/07/12 16:19:06 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*s_iteri(char *s, void (*f) (unsigned int, char *))
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return (s);
}