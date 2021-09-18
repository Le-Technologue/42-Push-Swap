/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:58:51 by wetieven          #+#    #+#             */
/*   Updated: 2021/07/22 11:15:12 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "chr.h"

// This atoi function uses ** to keep our pointer moving forward
// throughout parsing functions
//
int	ptr_atoi(char **str)
{
	unsigned long	res;
	int				sign;

	sign = 1;
	res = 0;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-' || **str == '+')
		if (*((*str)++) == '-')
			sign *= -1;
	while (ft_isdigit(**str) && **str)
	{
		res = res * 10 + (**str - 48);
		(*str)++;
	}
	if (res > 9223372036854775807)
	{
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	return (sign * res);
}
