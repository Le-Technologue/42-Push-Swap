/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:58:28 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 16:56:15 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_digit_count(long lnb, size_t base_len)
{
	size_t	i;

	i = 0;
	if (lnb < 0)
	{
		lnb = -lnb;
		i++;
	}
	while ((size_t)lnb >= base_len)
	{
		lnb /= base_len;
		i++;
	}
	i++;
	return (i);
}
