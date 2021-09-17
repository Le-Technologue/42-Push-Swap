/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_qcksrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:00:16 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/17 12:34:44 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst_mngr.h"
#include "psw_inssrt.h"
#include "psw_qcksrt.h"

void	lastsrt_a(t_game *game, size_t low, size_t high)
{
	if (high - low <= INSSRT_THRESHOLD)
		inssrt_a(game, low, high);
	else
		qcksrt_a(game, low, high, LAST);
	if (high - low > 31)
		qcksrt_b(game, low + (high - low) / 2, low, LAST);
}

static void	lastsrt_b(t_game *game, size_t high, size_t low)
{
	if (high - low <= INSSRT_THRESHOLD)
		inssrt_b(game, low, high);
	else
		qcksrt_b(game, high, low, LAST);
	if (high - low > 31)
		qcksrt_b(game, low + (high - low) / 2, low, LAST);
}

static void	nxtsrt(t_game *game, size_t low, size_t high, t_step step)
{
	if (high - low <= TWIN_INSSRT_THRSHLD)
		twin_inssrt(game, low, high);
	else
		qcksrt_a(game, low + (high - low) / 2 + 1, high, step);
	if (step != LAST && game->b.load)
		qcksrt_b(game, low + (high - low) / 2, low, B);
}

void	qcksrt_b(t_game *game, size_t high, size_t low, t_step step)
{
	size_t	med;
	size_t	to_sort;

	if (step != LAST && high - low <= LASTSRT_THRESHOLD)
		return (lastsrt_b(game, high, low));
	med = low + (high - low) / 2;
	to_sort = high - med;
	while (to_sort)
	{
		if (game->b.load && game->b.stk[game->b.load - 1].key > med)
		{
			psh(game, A);
			to_sort--;
		}
		else
			rot(game, B);
	}
	while (game->b.stk[0].key >= low && low != 0)
		rrot(game, B);
	nxtsrt(game, low, high, step);
}

void	qcksrt_a(t_game *game, size_t low, size_t high, t_step step)
{
	size_t	med;
	size_t	to_sort;

	if (step != LAST && high - low <= LASTSRT_THRESHOLD)
		return (lastsrt_a(game, low, high));
	med = low + (high - low) / 2;
	to_sort = (high - low) / 2 + 1;
	while (to_sort)
	{
		if (game->a.load && game->a.stk[game->a.load - 1].key <= med)
		{
			psh(game, B);
			to_sort--;
			if (to_sort > 1 && game->b.load >= 2
				&& game->b.stk[game->b.load - 1].key == med)
				rot(game, B);
		}
		else
			rot(game, A);
	}
	if (game->b.stk[0].key == med)
		rrot(game, B);
	while (game->a.stk[0].key <= high && high != game->info.qty - 1)
		rrot(game, A);
	nxtsrt(game, low, high, step);
}
