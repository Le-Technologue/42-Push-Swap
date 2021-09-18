/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 09:22:46 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 18:41:36 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

static char	**ft_failsafe(char **words, int count)
{
	while (--count >= 0)
		free(words[count]);
	free(words);
	return (NULL);
}

char	**ft_split(char const *str, char sep)
{
	char	**words;
	char	*start;
	int		i;

	words = malloc(sizeof(char *) * (ft_word_count(str, sep) + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == sep && *str)
			str++;
		start = (char *)str;
		while (*str != sep && *str)
			str++;
		if (str != start)
		{
			words[i] = malloc(sizeof(char) * (str - start + 1));
			if (!words[i])
				return (ft_failsafe(words, i));
			ft_strlcpy(words[i++], start, str - start + 1);
		}
	}
	words[i] = 0;
	return (words);
}
