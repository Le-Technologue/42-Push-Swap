/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:39:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/10 13:59:41 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TENTION
#include "libft.h"
#include "psw_inst.h"
#include "psw_qcksrt.h"
#include "psw_monitor.h"

void	psw_solver(t_game *game)
{
	if (MONITORING) // MONITORING
		psw_monitor(game);
//	if (LOAD_A < 10)
		psw_qcksrt_init(game, 0, TOP_A);
//	else
//		psw_qcksrt_init(game, 0, TOP_A - 5);
//	edge_srt(game, A_3, TOP_A / 2); //sort 3 last values in A
//	if (LOAD_B)
//		inssrt_b(game, TOP_B, 0);
//		psw_qcksort_B(game, PVT[LST_PVT] - 1, PVT[LST_PVT - 1]);
//	five_srt(game);
//	depiler B en terminant le tri
	buf_inst(game, END);
}
