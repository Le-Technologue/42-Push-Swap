/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 09:55:51 by wetieven          #+#    #+#             */
/*   Updated: 2021/04/05 19:22:38 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_word_count(const char *str, const char sep)
{
	int		res;
	char	*start;

	if (!str)
		return (-1);
	res = 0;
	while (*str)
	{
		while (*str == sep && *str)
			str++;
		start = (char *)str;
		while (*str != sep && *str)
			str++;
		if (str != start)
			res++;
	}
	return (res);
}
