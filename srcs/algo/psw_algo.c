/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:39:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/17 12:34:36 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"
#include "psw_inst_mngr.h"
#include "psw_qcksrt.h"
#include "psw_monitor.h"

static void	qcksrt_init(t_game *game, size_t low, size_t high)
{
	size_t	med;
	size_t	to_sort;

	if (high - low <= LASTSRT_THRESHOLD)
		return (lastsrt_a(game, low, high));
	med = low + (high - low) / 2;
	to_sort = (high - low) / 2 + 1;
	while (to_sort)
	{
		if (game->a.stk[game->a.load - 1].key <= med)
		{
			psh(game, B);
			if (game->b.load >= 2
				&& game->b.stk[game->b.load - 1 - 1].key > low + (med - low) / 2
				&& game->b.stk[game->b.load - 1].key <= low + (med - low) / 2)
				rot(game, B);
			to_sort--;
		}
		else
			rot(game, A);
	}
	qcksrt_a(game, med + 1, high, A_SPLT);
	qcksrt_b(game, med, low + (med - low) / 2 + 1, A_SPLT);
	qcksrt_b(game, low + (med - low) / 2, low, A_SPLT);
}

void	psw_solver(t_game *game)
{
	if (game->info.mon)
		psw_monitor(game);
	qcksrt_init(game, 0, game->a.load - 1);
	buf_inst(game, END);
}
