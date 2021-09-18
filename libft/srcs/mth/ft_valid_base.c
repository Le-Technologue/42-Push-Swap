/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:58:41 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 10:30:27 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "str.h"
#include "chr.h"

size_t	ft_valid_base(const char *base)
{
	char	*ptr;
	size_t	base_len;

	base_len = ft_strlen(base);
	if (base_len <= 1)
		return (0);
	while (*base)
	{
		ptr = (char *)(base + 1);
		if (*base == '-' || *base == '+' || ft_isspace(*base))
			return (0);
		while (*ptr && *base != *ptr)
			ptr++;
		if (*base == *ptr)
			return (0);
		base++;
	}
	return (base_len);
}
