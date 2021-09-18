/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 11:20:11 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 18:38:05 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

char	*ft_strmapi(char const *str, char (*fct)(unsigned int, char))
{
	int		i;
	char	*ret;

	if (!str)
		return (NULL);
	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret[i] = (*fct)(i, str[i]);
		++i;
	}
	ret[i] = '\0';
	return (ret);
}
