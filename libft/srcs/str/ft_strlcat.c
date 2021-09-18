/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 14:25:41 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 18:35:46 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "str.h"

size_t	ft_strlcat(char *stem, const char *appn, size_t dst_len)
{
	size_t	d;
	size_t	a;

	d = 0;
	a = 0;
	if (!stem && !appn)
		return (0);
	while (stem[d] != 0 && d < dst_len)
		d++;
	while (appn[a] != 0 && d + a + 1 < dst_len)
	{
		stem[d + a] = appn[a];
		a++;
	}
	if (d != dst_len)
		stem[d + a] = 0;
	return (ft_strlen(appn) + d);
}
