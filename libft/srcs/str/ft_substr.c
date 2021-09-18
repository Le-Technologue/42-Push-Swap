/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:53:15 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 18:36:22 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

char	*ft_substr(char const *src, unsigned int start, size_t dst_len)
{
	char	*ret;
	size_t	src_len;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src);
	if (start >= src_len)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (NULL);
		*ret = '\0';
	}
	else
	{
		if ((src_len - start) < dst_len)
			dst_len = src_len - start;
		ret = malloc(sizeof(char) * dst_len + 1);
		if (!ret)
			return (NULL);
		ft_strlcpy(ret, (src + start), dst_len + 1);
	}
	return (ret);
}
