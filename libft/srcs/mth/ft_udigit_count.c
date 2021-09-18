/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udigit_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:44:45 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 16:56:43 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_udigit_count(size_t nb, size_t base_len)
{
	size_t	i;

	i = 0;
	while (nb >= base_len)
	{
		nb /= base_len;
		i++;
	}
	i++;
	return (i);
}
