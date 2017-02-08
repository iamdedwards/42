/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_to_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 16:18:56 by dedwards          #+#    #+#             */
/*   Updated: 2016/09/20 13:39:48 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				s_to_i(const char *str)
{
	int				result;
	int				sign;
	int				i;

	result = 0;
	i = 0;
	sign = 1;
	while (s_haschar(" \b\f\n\t\r\v", str[i]))
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
		if (!c_is_digit(str[i]))
			return (0);
	}
	if (str[i] == '+')
		i++;
	while (c_is_digit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

unsigned int	s_n_to_ui(char *str, unsigned int untill)
{
	int				result;
	int				sign;
	int				i;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] && untill--)
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

int				s_n_to_i(char *str, unsigned int untill)
{
	int				result;
	int				sign;
	int				i;

	result = 0;
	i = 0;
	sign = 1;
	while (s_haschar(" \t", str[i]))
	{
		i++;
		untill--;
	}
	sign = (str[i] == '-') ? -1 : 1;
	i += (sign == -1) ? 1 : 0;
	while (str[i] && untill--)
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (sign * result);
}
