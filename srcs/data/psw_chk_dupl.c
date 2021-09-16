/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_chk_dupl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:42:41 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/16 11:28:16 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_error	assign_keys(t_val **set, size_t range)
{
	size_t	i;

	i = 0;
	while (i < range - 1)
	{
		if (set[i]->val == set[i + 1]->val)
			return (PARSE);
		set[i]->key = i;
		i++;
	}
	set[i]->key = i;
	return (CLEAR);
}

static void	mrg_both(t_val **set, t_val **buf,
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
		if (r > end || buf[l]->val <= set[r]->val)
			set[i++] = buf[l++];
		else
			set[i++] = set[r++];
	}
}

static void	cpy_left(t_val **buf, t_val **set, size_t start, const size_t end)
{
	while (start <= end)
	{
		buf[start] = set[start];
		start++;
	}
}

static t_error	psw_mrgsort(t_val **set, const size_t start, const size_t end)
{
	size_t			mid;
	static size_t	buf_size;
	static t_val	**buf = NULL;

	if (start >= end)
		return (CLEAR);
	if (!buf)
	{
		buf_size = end + 1;
		buf = malloc(sizeof(t_val **) * (buf_size));
		if (!buf)
			return (MEM_ALLOC);
	}
	mid = (start + end) / 2;
	psw_mrgsort(set, start, mid);
	psw_mrgsort(set, mid + 1, end);
	if (set[mid]->val > set[mid + 1]->val)
	{
		cpy_left(buf, set, start, mid);
		mrg_both(set + start, buf + start, mid - start, end - start);
	}
	if (end + 1 == buf_size && start == 0)
		free(buf);
	return (CLEAR);
}

t_error	psw_chk_dupl(t_game *game, long *buf)
{
	long	i;

	game->a.stk = malloc(sizeof(t_val) * GAME_QTY);
	if (!game->a.stk)
		return (MEM_ALLOC);
	i = -1;
	while (++i < (long)GAME_QTY)
		game->a.stk[i].val = buf[i];
	game->set = malloc(sizeof(t_val **) * GAME_QTY);
	if (!game->set)
	{
		free(game->a.stk);
		return (MEM_ALLOC);
	}
	i = -1;
	while (++i < (long)GAME_QTY)
		game->set[i] = &game->a.stk[i];
	if (psw_mrgsort(game->set, 0, GAME_QTY - 1) != CLEAR)
	{
		free(game->set);
		free(game->a.stk);
		return (MEM_ALLOC);
	}
	return (assign_keys(game->set, GAME_QTY));
}
