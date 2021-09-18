/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:37:21 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 16:55:20 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *src, const void *cmp, size_t n)
{
	while (n--)
		if (*((unsigned char *)src++) != *((unsigned char *)cmp++))
			return (*((unsigned char *)--src) - *((unsigned char *)--cmp));
	return (0);
}
