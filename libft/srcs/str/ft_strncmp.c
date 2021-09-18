/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:40:39 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 10:31:23 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *src, const char *cmp, size_t len)
{
	while (len && (*src || *cmp))
	{
		if (*src++ != *cmp++)
			return ((*(unsigned char *)--src) - (*(unsigned char *)--cmp));
		len--;
	}
	return (0);
}
