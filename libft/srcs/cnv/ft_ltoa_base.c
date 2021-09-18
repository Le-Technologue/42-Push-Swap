/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:57:54 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 10:00:44 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mth.h"

char	*ft_ltoa_base(long lnb, const char *base)
{
	char	*res;
	size_t	base_len;
	size_t	digit_count;

	base_len = ft_valid_base(base);
	if (!base_len)
		return (NULL);
	digit_count = ft_digit_count(lnb, base_len);
	res = malloc(sizeof(char) * (digit_count + 1));
	if (!res)
		return (NULL);
	if (lnb < 0)
	{
		res[0] = '-';
		lnb = -lnb;
	}
	res[digit_count] = '\0';
	while ((size_t)lnb >= base_len)
	{
		res[--digit_count] = base[lnb % base_len];
		lnb = lnb / base_len;
	}
	res[--digit_count] = base[lnb % base_len];
	return (res);
}
