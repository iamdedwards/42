/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_n_sign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedwards <dedwards@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 10:56:44 by dedwards          #+#    #+#             */
/*   Updated: 2016/08/09 15:52:49 by dedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ifdef_outsign(void (*func)(t_formatter **f, char *sign),
t_formatter **f, char *sign)
{
	if (func)
	{
		func(f, sign);
	}
	return (s_len(sign));
}

int			pf_n_sign(t_formatter **f,
void (*out_sign)(t_formatter **f, char *sign))
{
	int		ret;
	int		hexa_truc;
	char	type;

	type = (*f)->type.value | ' ';
	if (type == 'o' && (*f)->hash)
		return (ft_ifdef_outsign(out_sign, f, "0"));
	if (!(*f)->arg_str[0])
		return (0);
	ret = 0;
	if ((*f)->arg_str[0] == '-')
		return (ft_ifdef_outsign(out_sign, f, "-"));
	if ((*f)->plus && (type != 'u' && type != 'x'))
		ret += ft_ifdef_outsign(out_sign, f, "+");
	else if ((type != 'x' && type != 'u') && ((*f)->space))
		ret += ft_ifdef_outsign(out_sign, f, " ");
	hexa_truc = ((*f)->hash && (*f)->arg_str[0] != '0') || (type == 'p');
	if ((hexa_truc))
	{
		type = (type == 'p') ? 'x' : (*f)->type.value;
		ret += ft_ifdef_outsign(out_sign, f,
		(char[]){'0', type, '\0'});
	}
	return (ret);
}
