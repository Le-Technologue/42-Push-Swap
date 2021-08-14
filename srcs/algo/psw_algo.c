/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:39:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/14 22:33:22 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"
#include "psw_monitor.h"

t_error	srt_edges(t_game *game)
{
	if (LOAD_A && STK_A[TOP_A].key > STK_A[0].key
			&& STK_A[TOP_A].key < STK_A[TOP_A - 1].key)
		buf_inst(game, RRA);
	if (LOAD_B && STK_B[TOP_B].key < STK_B[0].key
			&& STK_B[TOP_B].key > STK_B[TOP_B - 1].key)
		buf_inst(game, RRB);

	if (LOAD_A > 3 && STK_A[TOP_A].key > STK_A[0].key)
		buf_inst(game, RA);
	if (LOAD_B > 3 && STK_B[TOP_B].key < STK_B[0].key)
		buf_inst(game, RB);

	if (LOAD_A > 2 && STK_A[TOP_A].key > STK_A[TOP_A - 1].key)
		buf_inst(game, SA);
	if (LOAD_B > 2 && STK_B[TOP_B].key < STK_B[TOP_B - 1].key)
		buf_inst(game, SB);

	if (LOAD_A > 3 && STK_A[0].key == STK_A[TOP_A].key + 1
			&& game->qty > 2)
		buf_inst(game, RRA);
	if (LOAD_B > 3 && STK_B[0].key == STK_B[TOP_B].key - 1
			&& game->qty > 2)
		buf_inst(game, RRB);
	if (STK_A[TOP_A].key > STK_A[TOP_A - 1].key)
		buf_inst(game, SA);
	if (STK_B[TOP_B].key < STK_B[TOP_B - 1].key)
		buf_inst(game, SB);

	if (STK_A[TOP_A].key < STK_A[TOP_A - 1].key
			&& STK_A[TOP_A - 1].key <= STK_A[0].key)
		return (CLEAR);
	return (ERROR);
}

void	psw_qcksrt(t_game *game, size_t start, size_t end)
{
	size_t	med;
	size_t	to_sort;
	_Bool	restore_med;

	if (start >= end)
		return ;
	restore_med = 0;
	med = start + (end - start) / 2;
	to_sort = (end - start) / 2 + 1;
	while (to_sort) 
	{
		if (STK_A[TOP_A].key == med)
		{
			buf_inst(game, PB);
			to_sort--;
			if (to_sort > 0 && to_sort != (end - start) / 2)
			{
				buf_inst(game, RB);
				restore_med = 1;
			}
		}
		else if (STK_A[TOP_A].key < med)
		{
			buf_inst(game, PB);
			to_sort--;
		}
		else
			buf_inst(game, RA);
	}
	if (restore_med || STK_A[0].key == med)
		buf_inst(game, RRB);
//	while (srt_edges(game))
//		;
//	psw_qcksrt(game, 0, med); //inverted logic here ?
	psw_qcksrt(game, med + 1, end);

}

void	psw_solver(t_game *game)
{
	if (game->mon)
		psw_monitor(game, 0);
//	while (srt_edges(game))
//		;
	psw_qcksrt(game, 0, TOP_A);
//	srt_edges(game);
	buf_inst(game, END);
}
