/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:32:43 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 14:46:29 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

char	*ft_strdup(const char *src)
{
	char	*ret;

	ret = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (ret)
		ft_strcpy(ret, src);
	return (ret);
}
