/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:19:16 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 10:28:33 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mem.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ret;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	ret = dst;
	while (n--)
		*((unsigned char *)dst++) = *((unsigned char *)src++);
	return (ret);
}
