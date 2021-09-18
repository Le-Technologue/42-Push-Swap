/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 11:23:48 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/06 12:36:48 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mem.h"

t_error	rot_arr_l_to_r(void *arr, size_t unit_size, size_t len, size_t span)
{
	void	*rightmost;

	span %= len;
	if (span == 0)
		return (CLEAR);
	span *= unit_size;
	rightmost = malloc(span);
	if (!rightmost)
		return (MEM_ALLOC);
	ft_memcpy(rightmost, arr + len * unit_size - span, span);
	ft_memmove(arr + span, arr, len * unit_size - span);
	ft_memcpy(arr, rightmost, span);
	free(rightmost);
	return (CLEAR);
}

t_error	rot_arr_r_to_l(void *arr, size_t unit_size, size_t len, size_t span)
{
	void	*leftmost;

	span %= len;
	if (span == 0)
		return (CLEAR);
	span *= unit_size;
	leftmost = malloc(span);
	if (!leftmost)
		return (MEM_ALLOC);
	ft_memcpy(leftmost, arr, span);
	ft_memmove(arr, arr + span, len * unit_size - span);
	ft_memcpy(arr + len * unit_size - span, leftmost, span);
	free(leftmost);
	return (CLEAR);
}
