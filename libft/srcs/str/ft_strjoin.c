/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 08:16:00 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 18:41:00 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

char	*ft_strjoin(char const *pre, char const *post)
{
	char	*ret;
	int		ret_len;

	if (!pre || !post)
		return (NULL);
	ret_len = ft_strlen(pre) + ft_strlen(post) + 1;
	ret = malloc(sizeof(char) * (ret_len));
	if (!ret)
		return (NULL);
	ft_strcpy(ret, pre);
	ft_strlcat(ret, post, ret_len);
	return (ret);
}
