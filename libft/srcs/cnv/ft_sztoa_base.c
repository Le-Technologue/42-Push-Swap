/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sztoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:30:19 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 10:00:56 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mth.h"

char	*ft_sztoa_base(size_t nb, const char *base)
{
	char	*res;
	size_t	base_len;
	size_t	digit_count;

	base_len = ft_valid_base(base);
	if (!base_len)
		return (NULL);
	digit_count = ft_udigit_count(nb, base_len);
	res = malloc(sizeof(char) * (digit_count + 1));
	if (!res)
		return (NULL);
	res[digit_count] = '\0';
	while (digit_count)
	{
		res[--digit_count] = base[nb % base_len];
		nb = nb / base_len;
	}
	return (res);
}
