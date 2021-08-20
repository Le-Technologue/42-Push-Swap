/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:39:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/20 19:24:17 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TENTION
#include "libft.h"
#include "psw_inst.h"
#include "psw_monitor.h"
#include "psw_algo.h"

void	swp(t_game *game, char stk)
{
	if (stk == 'A')
	{
		if (LOAD_A == 2 && PRV_MOV == RB) //opti marginale ?
			buf_inst(game, RA);
		else if (LOAD_A == 2 && PRV_MOV == RRB)
			buf_inst(game, RRA);
		else
			buf_inst(game, SA);
	}
	if (stk == 'B')
	{
		if (LOAD_B == 2 && PRV_MOV == RA)
			buf_inst(game, RB);
		else if (LOAD_B == 2 && PRV_MOV == RRA)
			buf_inst(game, RRB);
		else
			buf_inst(game, SB);
	}
}

void	rot(t_game *game, char stk)
{
	if (stk == 'A')
	{
		if (LOAD_A == 2 && PRV_MOV == SB) //opti marginale ?
			buf_inst(game, SA);
		else if (LOAD_A == 2 && PRV_MOV == RRB)
			buf_inst(game, RRA);
		else
			buf_inst(game, RA);
	}
	if (stk == 'B')
	{
		if (LOAD_B == 2 && PRV_MOV == SA)
			buf_inst(game, SB);
		else if (LOAD_B == 2 && PRV_MOV == RRA)
			buf_inst(game, RRB);
		else
			buf_inst(game, RB);
	}
}

void	rrot(t_game *game, char stk)
{
	if (stk == 'A')
	{
		if (LOAD_A == 2 && PRV_MOV == SB) //opti marginale ?
			buf_inst(game, SA);
		else if (LOAD_A == 2 && PRV_MOV == RB)
			buf_inst(game, RA);
		else
			buf_inst(game, RRA);
	}
	if (stk == 'B')
	{
		if (LOAD_B == 2 && PRV_MOV == SA)
			buf_inst(game, SB);
		else if (LOAD_B == 2 && PRV_MOV == RA)
			buf_inst(game, RB);
		else
			buf_inst(game, RRB);
	}
}

void	srt_tops(t_game *game, t_mode step, size_t med)
{
	if (LOAD_A >= 2 && (STK_A[TOP_A].key > STK_A[TOP_A - 1].key))
	{
		if (step == A
			&& ((STK_A[TOP_A].key <= med && STK_A[TOP_A - 1].key <= med)
			|| (STK_A[TOP_A].key > med && STK_A[TOP_A - 1].key > med)))
			swp(game, 'A');
		if (step == START
			&& ((STK_A[TOP_A].key > med / 2 && STK_A[TOP_A - 1].key > med / 2)
			|| (STK_B[TOP_B].key <= med / 2
				&& (STK_A[TOP_A].key < med && STK_A[TOP_A - 1].key < med))))
			swp(game, 'A');
	}
	if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[TOP_B - 1].key)
		swp(game, 'B');
}

void	srt_bottoms(t_game *game, char stack, size_t med)
{
	if (PRV_MOV != RA && stack != 'B' && STK_A[0].key != med
			&& LOAD_A > 3 && STK_A[TOP_A].key > STK_A[0].key
			&& STK_A[TOP_A].key < STK_A[TOP_A - 1].key)
		rrot(game, 'A');
	if (PRV_MOV != RB && stack != 'A' && STK_B[0].key != med
			&& LOAD_B > 3 && STK_B[TOP_B].key < STK_B[0].key
			&& STK_B[TOP_B].key > STK_B[TOP_B - 1].key)
		rrot(game, 'B');
	if (PRV_MOV != RRA && LOAD_A > 3 && STK_A[TOP_A].key > STK_A[0].key)
		rot(game, 'A');
	if (PRV_MOV != RRB && stack != 'A' && STK_B[0].key != med
			&& LOAD_B > 3 && STK_B[TOP_B].key < STK_B[0].key)
		rot(game, 'B');
}

void	srt_next_to_top(t_game *game, t_mode step, size_t med)
{
	if (PRV_MOV != RA && LOAD_A > 3 && STK_A[0].key == STK_A[TOP_A].key + 1
			&& game->qty > 2)
		rrot(game, 'A');
	if (PRV_MOV != RB && LOAD_B > 3 && STK_B[0].key == STK_B[TOP_B].key - 1
			&& game->qty > 2)
		rrot(game, 'B');
	srt_tops(game, step, med);
}

void	srt_edges(t_game *game, char stack, t_mode step, size_t med)
{
	int loop;

	loop = 0;
	while ((LOAD_A > 1 && (STK_A[TOP_A].key > STK_A[TOP_A - 1].key))
			|| (LOAD_B > 1 && (STK_B[TOP_B].key < STK_B[TOP_B - 1].key)))
	{
		srt_bottoms(game, stack, med);
		srt_tops(game, step, med);
		srt_next_to_top(game, step, med);
		loop++;
		if (loop > 100)
		{
			dprintf(1, ">>>>>>> !!!!!  LOOP !!!!! <<<<<<<<\n\n");
			psw_monitor(game, game->log->entries * game->log->unit_size - game->log->unit_size * 8);
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
				buf_inst(game, RB);
		}
		srt_edges(game, 'A', A, med);
		if (STK_A[TOP_A].key < med)
		{
			buf_inst(game, PB);
			to_sort--;
		}
		else
			buf_inst(game, RA);
		srt_edges(game, 'A', A, med);
	}
	if (STK_B[0].key == med)
		buf_inst(game, RRB);
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
		srt_edges(game, 'A', START, med);
		if (STK_A[TOP_A].key <= med)
		{
			buf_inst(game, PB);
			if (!higher_than_med_on_stack && STK_B[TOP_B].key > med / 2)
				higher_than_med_on_stack = 1;
			else if (higher_than_med_on_stack && STK_B[TOP_B].key <= med / 2)
				buf_inst(game, RB);
			to_sort--;
		}
		else
			buf_inst(game, RA);
	}
//	vctr_push(game->pvt, med);
	psw_qcksrt_A(game, med + 1, end);
}

void	psw_solver(t_game *game)
{
	if (game->info.mon)
		psw_monitor(game, 0);
	psw_qcksrt_init(game, 0, TOP_A);
//	srt_edges(game, 'C', ); //sort 3 last values in A
//	depiler B en terminant le tri
	buf_inst(game, END);
}
