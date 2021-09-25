/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:39:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/25 10:12:03 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"
#include "psw_inst_mngr.h"
#include "psw_qcksrt.h"
#include "psw_inssrt.h"
#include "psw_probes.h"
#include "psw_monitor.h"

static void	qcksrt_init(t_game *game, size_t low, size_t high)
{
	size_t	to_sort;

	if (LASTSRT_THRESHOLD && !sorted(game, A, 0))
		return (lastsrt_a(game, low, high));
	to_sort = (high - low) / 2 + 1;
	while (to_sort && !sorted(game, A, 0))
	{
		if (STK_A[TOP_A].key <= MED)
		{
			psh(game, B);
			if (LOAD_B >= 2 && STK_B[TOP_B - 1].key > L_HLFMED
				&& STK_B[TOP_B].key <= L_HLFMED)
				rot(game, B);
			to_sort--;
		}
		else
			rot(game, A);
	}
	if (sorted(game, A, 0))
		return (inssrt_b(game, STK_A[TOP_A].key - 1, low));
	qcksrt_a(game, MED + 1, high, A_SPLT);
	qcksrt_b(game, MED, L_HLFMED + 1, A_SPLT);
	qcksrt_b(game, L_HLFMED, low, A_SPLT);
}

void	psw_solver(t_game *game)
{
	if (MONITORING)
		psw_monitor(game);
	qcksrt_init(game, 0, TOP_A);
	buf_inst(game, END);
}
