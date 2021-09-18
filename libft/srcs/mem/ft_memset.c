/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:52:13 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 16:55:42 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *src, int c, size_t len)
{
	void	*ret;

	ret = src;
	while (len--)
		*((unsigned char *)src++) = (unsigned char)c;
	return (ret);
}
