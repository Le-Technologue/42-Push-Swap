/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:00:38 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 10:31:47 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*ret;

	ret = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			ret = (char *)str;
		str++;
	}
	if (c == '\0')
		ret = (char *)str;
	return (ret);
}
