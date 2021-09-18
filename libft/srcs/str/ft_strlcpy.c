/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:50:08 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 18:35:02 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "mem.h"
#include "str.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_len)
{
	size_t	src_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (src_len + 1 < dst_len)
	{
		ft_memcpy(dst, src, src_len);
		dst[src_len] = '\0';
	}
	else if (dst_len)
	{
		ft_memcpy(dst, src, dst_len);
		dst[dst_len - 1] = '\0';
	}
	return (src_len);
}
