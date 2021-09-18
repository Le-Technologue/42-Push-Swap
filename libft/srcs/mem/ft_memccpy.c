/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:53:23 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 10:23:28 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	if (!dst && !src)
		return (NULL);
	while (len--)
	{
		*((unsigned char *)dst++) = *((unsigned char *)src);
		if (*((unsigned char *)src++) == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}
