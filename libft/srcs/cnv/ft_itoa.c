/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:47:08 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 10:00:36 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mth.h"

char	*ft_itoa(int nb)
{
	long	lnb;
	char	*res;
	size_t	digit_count;

	lnb = nb;
	digit_count = ft_digit_count(lnb, 10);
	res = malloc(sizeof(char) * (digit_count + 1));
	if (!res)
		return (NULL);
	if (lnb < 0)
	{
		res[0] = '-';
		lnb = -lnb;
	}
	res[digit_count] = '\0';
	while (lnb >= 10)
	{
		res[--digit_count] = lnb % 10 + 48;
		lnb = lnb / 10;
	}
	res[--digit_count] = lnb % 10 + 48;
	return (res);
}
