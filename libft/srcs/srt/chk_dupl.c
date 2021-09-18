/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_dupl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:40:03 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/02 21:54:17 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "typ.h"

t_error	chk_dupl(size_t *idx, const int unit_size,
					const void *set, const size_t end)
{
	int	unit_idx;
	int	dble;

	if (unit_size <= 0)
		return (PARSE);
	while (*idx <= end - 1)
	{
		dble = 0;
		unit_idx = 0;
		while (unit_idx < unit_size)
		{
			if (*((char *)set + ((*idx) * unit_size + unit_idx))
				== *((char *)set + (((*idx) + 1) * unit_size + unit_idx)))
				dble++;
			else
				dble = 0;
			unit_idx++;
		}
		(*idx)++;
		if (dble == unit_size)
			return (ERROR);
	}
	return (CLEAR);
}
