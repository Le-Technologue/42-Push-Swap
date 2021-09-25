/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_qcksrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:00:16 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/25 09:47:21 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst_mngr.h"
#include "psw_inssrt.h"
#include "psw_qcksrt.h"

void	lastsrt_a(t_game *game, size_t low, size_t high)
{
	if (INSSRT_THRESHOLD)
		inssrt_a(game, low, high);
	else
		qcksrt_a(game, low, high, LAST);
	if (LOAD_B && high - low > 31)
		qcksrt_b(game, MED, low, LAST);
}

static void	lastsrt_b(t_game *game, size_t high, size_t low)
{
	if (INSSRT_THRESHOLD)
		inssrt_b(game, high, low);
	else
		qcksrt_b(game, high, low, LAST);
	if (LOAD_B && high - low > 31)
		qcksrt_b(game, MED, low, LAST);
}

static void	nxtsrt(t_game *game, size_t low, size_t high, t_step step)
{
	if (TWIN_INSSRT_THRSHLD)
		twin_inssrt(game, low, high);
	else
		qcksrt_a(game, MED + 1, high, step);
	if (step != LAST && LOAD_B)
		qcksrt_b(game, MED, low, B);
}

void	qcksrt_b(t_game *game, size_t high, size_t low, t_step step)
{
	size_t	to_sort;

	if (step != LAST && LASTSRT_THRESHOLD)
		return (lastsrt_b(game, high, low));
	to_sort = high - MED;
	while (LOAD_B && to_sort)
	{
		if (STK_B[TOP_B].key > MED)
		{
			psh(game, A);
			to_sort--;
		}
		else
			rot(game, B);
	}
	while (LOAD_B && STK_B[0].key >= low && low != 0)
		rrot(game, B);
	nxtsrt(game, low, high, step);
}

void	qcksrt_a(t_game *game, size_t low, size_t high, t_step step)
{
	size_t	to_sort;

	if (step != LAST && LASTSRT_THRESHOLD)
		return (lastsrt_a(game, low, high));
	to_sort = (high - low) / 2 + 1;
	while (LOAD_A && to_sort)
	{
		if (STK_A[TOP_A].key <= MED)
		{
			psh(game, B);
			to_sort--;
			if (to_sort > 1 && LOAD_B >= 2 && STK_B[TOP_B].key == MED)
				rot(game, B);
		}
		else
			rot(game, A);
	}
	if (LOAD_B && STK_B[0].key == MED)
		rrot(game, B);
	while (LOAD_A && STK_A[0].key <= high && high != GAME_QTY - 1)
		rrot(game, A);
	nxtsrt(game, low, high, step);
}
