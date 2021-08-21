/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:39:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/21 13:49:51 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TENTION
#include "libft.h"
#include "psw_opti.h"
#include "psw_algo.h"
#include "psw_monitor.h"

void	srt_tops(t_game *game, t_mode step, size_t med, _Bool *loop)
{
	if (LOAD_A >= 2 && (STK_A[TOP_A].key > STK_A[TOP_A - 1].key))
	{
		if (step == A
			&& ((STK_A[TOP_A].key < med && STK_A[TOP_A - 1].key < med)
			|| (STK_A[TOP_A].key > med && STK_A[TOP_A - 1].key > med)))
		{
			swp(game, 'A');
			*loop = 0;
		}
		if (step == START
			&& ((STK_A[TOP_A].key > med && STK_A[TOP_A - 1].key > med)
			|| ((STK_A[TOP_A].key > med / 2 && STK_A[TOP_A - 1].key > med / 2)
				&& (STK_A[TOP_A].key <= med && STK_A[TOP_A - 1].key <= med))
			|| (STK_B[TOP_B].key <= med / 2
				&& (STK_A[TOP_A].key <= med && STK_A[TOP_A - 1].key <= med))))
		{
			swp(game, 'A');
			*loop = 0;
		}
		if (step == FINISH)
		{
			swp(game, 'A');
			*loop = 0;
		}
	}
	if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[TOP_B - 1].key)
	{
		swp(game, 'B');
		*loop = 0;
	}
}

void	srt_bottoms(t_game *game, t_mode step, size_t med, _Bool *loop)
{
	if (PRV_MOV != RA //&& step != B
			&& LOAD_A >= 3 && STK_A[TOP_A].key > STK_A[0].key
			&& (STK_A[TOP_A].key <= med || STK_A[0].key <= med))
//			&& (STK_A[0].key != med || step == FINISH)
//			&& STK_A[TOP_A].key < STK_A[TOP_A - 1].key
	{
		rrot(game, 'A');
		*loop = 0;
	}
	if (PRV_MOV != RB && STK_B[0].key != med // && step != A 
			&& LOAD_B >= 3 && STK_B[TOP_B].key < STK_B[0].key
			&& STK_B[TOP_B].key > STK_B[TOP_B - 1].key)
	{
		rrot(game, 'B');
		*loop = 0;
	}
	if (PRV_MOV != RRA && LOAD_A >= 3 && STK_A[TOP_A].key > STK_A[0].key)
	{
		rot(game, 'A');
		*loop = 0;
	}
	if (PRV_MOV != RRB && step != A && STK_B[0].key != med
			&& LOAD_B >= 3 && STK_B[TOP_B].key < STK_B[0].key)
	{
		rot(game, 'B');
		*loop = 0;
	}
}

void	srt_next_to_top(t_game *game, t_mode step, size_t med, _Bool *loop)
{
	if (PRV_MOV != RA && LOAD_A > 3 && STK_A[0].key == STK_A[TOP_A].key + 1
			&& game->qty > 2)
	{
		rrot(game, 'A');
		*loop = 0;
	}
	if (PRV_MOV != RB && LOAD_B > 3 && STK_B[0].key == STK_B[TOP_B].key - 1
			&& game->qty > 2)
	{
		rrot(game, 'B');
		*loop = 0;
	}
	srt_tops(game, step, med, loop);
}

void	srt_edges(t_game *game, t_mode step, size_t med)
{
	_Bool loop;

	while ((LOAD_A > 1 && (STK_A[TOP_A].key > STK_A[TOP_A - 1].key))
			|| (LOAD_B > 1 && (STK_B[TOP_B].key < STK_B[TOP_B - 1].key)))
	{
		loop = 1;
		srt_tops(game, step, med, &loop);
		srt_bottoms(game, step, med, &loop);
		srt_tops(game, step, med, &loop);
//		srt_next_to_top(game, step, med, &loop);
		if (loop)
		{
			dprintf(1, ">>>>>>> !!!!!  LOOP !!!!! <<<<<<<<\n\n");
			psw_monitor(game);
			dprintf(1, ">>>>>>> !!!!!  LOOP !!!!! <<<<<<<<\n\n");
			break;
		}
	}
}
// from last sorted value to last_pvt,
// then from last_pvt to previous last_pvt
/*
void	psw_qcksrt_B(t_game *game, size_t end, size_t start)
{
	size_t	med;
	size_t	to_sort;

	if (end - start <= 3)
		return ;
	med = start + (end - last_pvt) / 2;
	to_sort = (end - start) / 2 + 1;
	while (STK_B[end--].key != start)
	{
		srt_edges(game, 'B', med);
		if (STK_A[TOP_A].key == med)
		{
			buf_inst(game, PB);
			to_sort--;
			if (to_sort > 0 && to_sort != (end - start) / 2)
				buf_inst(game, RB);
		}
		else if (STK_A[TOP_A].key < med)
		{
			buf_inst(game, PB);
			to_sort--;
		}
		else
			buf_inst(game, RA);
	}
	if (STK_B[0].key == med)
		buf_inst(game, RRB);
	psw_qcksrt_B(game, 0, med);
}
*/
void	psw_qcksrt_A(t_game *game, size_t start, size_t end)
{
	size_t	med;
	size_t	to_sort;

	if (end - start <= 3)
		return ;
	med = start + (end - start) / 2;
	to_sort = (end - start) / 2 + 1;
	while (to_sort && LOAD_A > 3) 
	{
		if (STK_A[TOP_A].key == med)
		{
			buf_inst(game, PB);
			to_sort--;
			if (to_sort > 0 && to_sort != (end - start) / 2)
				rot(game, 'B');
		}
		srt_edges(game, A, med);
		if (STK_A[TOP_A].key < med)
		{
			buf_inst(game, PB);
			to_sort--;
		}
		else
			rot(game, 'A');
		srt_edges(game, A, med);
	}
	if (STK_B[0].key == med)
		rrot(game, 'B');
//	vctr_push(game->pvt, med);
	psw_qcksrt_A(game, med + 1, end);
}

void	psw_qcksrt_init(t_game *game, size_t start, size_t end)
{
	size_t	med;
	size_t	to_sort;
	_Bool	higher_than_med_on_stack;

	if (end - start <= 3)
		return ;
	med = start + (end - start) / 2;
	to_sort = (end - start) / 2 + 1;
	higher_than_med_on_stack = 0;
	while (to_sort && LOAD_A > 3) 
	{
		srt_edges(game, START, med);
		if (STK_A[TOP_A].key <= med)
		{
			buf_inst(game, PB);
			if (!higher_than_med_on_stack && STK_B[TOP_B].key > med / 2)
				higher_than_med_on_stack = 1;
			else if (higher_than_med_on_stack && STK_B[TOP_B].key <= med / 2)
				rot(game, 'B');
			to_sort--;
		}
		else
			rot(game, 'A');
	}
//	vctr_push(game->pvt, med);
	psw_qcksrt_A(game, med + 1, end);
}

void	psw_solver(t_game *game)
{
	if (game->info.mon)
		psw_monitor(game);
	psw_qcksrt_init(game, 0, TOP_A);
//	srt_edges(game, 'C', ); //sort 3 last values in A
//	depiler B en terminant le tri
	buf_inst(game, END);
}
