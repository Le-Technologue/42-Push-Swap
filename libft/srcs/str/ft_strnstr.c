/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:42:54 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 10:31:33 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!haystack && !needle)
		return (NULL);
	while (*haystack && needle[i] && len--)
	{
		if (*haystack++ == needle[i])
			i++;
		else
		{
			haystack = haystack - i;
			len += i;
			i = 0;
		}
	}
	if (!needle[i])
		return ((char *)(haystack - i));
	return (NULL);
}
