/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 09:32:01 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 18:37:06 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

char	*ft_strtrim(char const *str, char const *charset)
{
	char	*start;
	char	*ret;

	if (!str)
		return (NULL);
	while (*str && ft_strchr(charset, *((char *)str)))
		str++;
	start = (char *)str;
	while (*str)
		str++;
	while (ft_strchr(charset, *((char *)str)) && str >= start)
		str--;
	str++;
	ret = malloc(sizeof(char) * (str - start + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, start, str - start + 1);
	return (ret);
}
