/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:13:58 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 10:28:23 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *src, int c, size_t len)
{
	while (len--)
	{
		if (*(unsigned char *)src++ == (unsigned char)c)
			return ((unsigned char *)--src);
	}
	return (NULL);
}
