/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrg_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:37:19 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/02 14:19:54 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "typ.h"

static void	mrg_both(int *set, const int *buf,
					const size_t rift, const size_t end)
{
	size_t	i;
	size_t	l;
	size_t	r;

	i = 0;
	l = 0;
	r = rift + 1;
	while (l <= rift)
	{
		if (r > end || buf[l] <= set[r])
			set[i++] = buf[l++];
		else
			set[i++] = set[r++];
	}
}

static void	cpy_left(int *buf, const int *set, size_t start, const size_t end)
{
	while (start <= end)
	{
		buf[start] = set[start];
		start++;
	}
}

void	mrg_sort(int *set, const size_t start, const size_t end)
{
	size_t			mid;
	static size_t	buf_size;
	static int		*buf = NULL;

	if (start >= end)
		return ;
	if (!buf)
	{
		buf_size = end + 1;
		buf = malloc(sizeof(int) * (buf_size));
		if (!buf)
			return ;
	}
	mid = (start + end) / 2;
	mrg_sort(set, start, mid);
	mrg_sort(set, mid + 1, end);
	if (set[mid] > set[mid + 1])
	{
		cpy_left(buf, set, start, mid);
		mrg_both(set + start, buf + start, mid - start, end - start);
	}
	if (end + 1 == buf_size && start == 0)
		free(buf);
}
// tester
/*
t_error	chk_dupl(size_t *idx, const int unit_size,
					const void *set, const size_t end)
{
	int	unit_idx;
	int	dble;

	if (unit_size <= 0)
		return (parameter);
	while (*idx <= end)
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
			return (error);
	}
	return (clear);
}

int	main(int ac, char **av)
{
	int	*set;
	size_t	i;

	set = malloc(sizeof(int) * (--ac));
	if (!set)
		return 1;
	i = 0;
	while (i < ac)
	{
		set[i] = atoi(av[i + 1]);
		i++;
	}
	dprintf(1, "incoming list :\n");
	for (i = 0 ; i < ac ; i++)
		dprintf(1, "%i ", set[i]);
	mrg_sort(set, 0, ac - 1);
	dprintf(1, "\n outgoing list :\n");
	for (i = 0 ; i < ac ; i++)
		dprintf(1, "%i ", set[i]);
	dprintf(1, "\n");
	i = 0;
	if (!chk_dupl(&i, sizeof(int), set, ac - 1))
		dprintf(1, "No duplicates in this set\n");
	else
		dprintf(1, "Duplicate found at index %i\n", i);
	free(set);
	return 0;
}
*/
