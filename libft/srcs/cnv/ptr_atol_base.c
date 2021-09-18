/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_atol_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:32:06 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/16 10:24:43 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "chr.h"
#include "str.h"
#include "mth.h"

long	ptr_atol_base(char **str, const char *base)
{
	unsigned long	res;
	int				sign;
	size_t			base_len;
	int				chr_val;

	sign = 1;
	res = 0;
	base_len = ft_strlen(base);
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-' || **str == '+')
		if (*((*str)++) == '-')
			sign *= -1;
	chr_val = ft_in_da_base(**str, base);
	while (chr_val != -1)
	{
		res = res * base_len + chr_val;
		chr_val = ft_in_da_base(*(++(*str)), base);
	}
	if (res > LONG_MAX && sign == -1)
		return (LONG_MIN);
	if (res >= LONG_MAX && sign == 1)
		return (LONG_MAX);
	return (sign * res);
}
