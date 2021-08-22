/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:39:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/22 14:26:38 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TENTION
#include "libft.h"
#include "psw_inst.h"
#include "psw_algo.h"
#include "psw_opti.h"
#include "psw_monitor.h"

void	srt_tops(t_game *game, t_mode step, size_t med, _Bool *loop)
{
	if (LOAD_A >= 2 && (STK_A[TOP_A].key > STK_A[TOP_A - 1].key))
	{
		if (step == START
			&& ((STK_A[TOP_A].key > med && STK_A[TOP_A - 1].key > med)
			|| ((STK_A[TOP_A].key > med / 2 && STK_A[TOP_A - 1].key > med / 2)
				&& (STK_A[TOP_A].key <= med && STK_A[TOP_A - 1].key <= med))
			|| (STK_B[TOP_B].key <= med / 2
				&& (STK_A[TOP_A].key <= med && STK_A[TOP_A - 1].key <= med))))
			swp(game, A);
		else if (step == A
			&& ((STK_A[TOP_A].key < med && STK_A[TOP_A - 1].key < med)
			|| (STK_A[TOP_A].key > med && STK_A[TOP_A - 1].key > med)))
			swp(game, A);
		else if (step == A_3)
			swp(game, A);
		else
			*loop = 1;
	}
	if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[TOP_B - 1].key
			&& STK_B[TOP_B - 1].key != med)
	{
		swp(game, B);
		*loop = 0;
	}
}

void	srt_bottoms(t_game *game, size_t med, _Bool *loop)
{
	*loop = 1;
	if (PRV_MOV != RA && LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[0].key
			&& (STK_A[TOP_A].key <= med && STK_A[0].key <= med))
	{
		rrot(game, A);
		*loop = 0;
	}
	if (PRV_MOV != RB && LOAD_B >= 2 && STK_B[0].key != med
			&& STK_B[TOP_B].key < STK_B[0].key)
	{
		rrot(game, B);
		*loop = 0;
	}
	if (PRV_MOV != RRA && LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[0].key
			&& (STK_A[TOP_A].key >= med && STK_A[0].key >= med))
	{
		rot(game, A);
		*loop = 0;
	}
	if (PRV_MOV != RRB && LOAD_B >= 2 && STK_B[0].key != med
			&& STK_B[TOP_B].key < STK_B[0].key)
	{
		rot(game, B);
		*loop = 0;
	}
}

void	srt_next_to_top(t_game *game, size_t med, _Bool *loop)
{
	*loop = 1;
	if (PRV_MOV != RA && LOAD_A >= 3 && STK_A[0].key == STK_A[TOP_A].key + 1
			&& (STK_A[TOP_A].key <= med && STK_A[0].key <= med))
	{
		rrot(game, A);
		*loop = 0;
	}
	if (PRV_MOV != RB && LOAD_B >= 3 && STK_B[0].key == STK_B[TOP_B].key - 1
			&& (STK_A[TOP_A].key >= med && STK_A[0].key >= med))
	{
		rrot(game, B);
		*loop = 0;
	}
}

void	edge_srt(t_game *game, t_mode step, size_t med)
{
	_Bool loop;

	while ((LOAD_A > 1 && (STK_A[TOP_A].key > STK_A[TOP_A - 1].key))
			|| (LOAD_B > 1 && (STK_B[TOP_B].key < STK_B[TOP_B - 1].key)))
	{
		loop = 0;
		srt_tops (game, step, med, &loop);
		srt_bottoms(game, med, &loop);
		srt_tops (game, step, med, &loop);
		srt_next_to_top(game, med, &loop);
		srt_tops (game, step, med, &loop);
		if (loop)
			break;
	}
}

/*
void	srt_bottoms(t_game *game, t_mode step, size_t med, _Bool *loop)
{
	(void)step; // probably redundant
	if (PRV_MOV != RA // && step != B
			&& LOAD_A >= 3 && STK_A[TOP_A].key > STK_A[0].key
			&& (STK_A[TOP_A].key <= med && STK_A[0].key <= med))
//			&& (STK_A[0].key != med || step == A_3)
//			&& STK_A[TOP_A].key < STK_A[TOP_A - 1].key
	{
		rrot(game, A);
		*loop = 0;
	}
	if (PRV_MOV != RB && STK_B[0].key != med // && step != A 
			&& LOAD_B >= 3 && STK_B[TOP_B].key < STK_B[0].key
			&& STK_B[TOP_B].key > STK_B[TOP_B - 1].key)
	{
		rrot(game, B);
		*loop = 0;
	}
	if (PRV_MOV != RRA && LOAD_A >= 3 && STK_A[TOP_A].key > STK_A[0].key
			&& (STK_A[TOP_A].key >= med && STK_A[0].key >= med))
	{
		rot(game, A);
		*loop = 0;
	}
	if (PRV_MOV != RRB && STK_B[0].key != med // && step != A
			&& LOAD_B >= 3 && STK_B[TOP_B].key < STK_B[0].key)
	{
		rot(game, B);
		*loop = 0;
	}
}

void	srt_next_to_top(t_game *game, t_mode step, size_t med, _Bool *loop)
{
	if (PRV_MOV != RA && LOAD_A >= 3 && STK_A[0].key == STK_A[TOP_A].key + 1
			&& (STK_A[TOP_A].key <= med && STK_A[0].key <= med))
	{
		rrot(game, A);
		*loop = 0;
	}
	if (PRV_MOV != RB && LOAD_B >= 3 && STK_B[0].key == STK_B[TOP_B].key - 1
			&& (STK_A[TOP_A].key >= med && STK_A[0].key >= med))
	{
		rrot(game, B);
		*loop = 0;
	}
	srt_tops(game, step, med, loop);
}

void	edge_srt(t_game *game, t_mode step, size_t med)
{
	_Bool loop;

	while ((LOAD_A > 1 && (STK_A[TOP_A].key > STK_A[TOP_A - 1].key))
			|| (LOAD_B > 1 && (STK_B[TOP_B].key < STK_B[TOP_B - 1].key)))
	{
		loop = 1;
		srt_tops(game, step, med, &loop);
		srt_bottoms(game, step, med, &loop);
		srt_tops(game, step, med, &loop);
		srt_next_to_top(game, step, med, &loop);
		if (loop)
		{
//			dprintf(1, ">>>>>>> !!!!! vvvv LOOP vvvv !!!!! <<<<<<<<\n");
//			psw_monitor(game);
//			dprintf(1, ">>>>>>> !!!!! ^^^^ LOOP ^^^^ !!!!! <<<<<<<<\n\n");
			break;
		}
	}
}
*/
// from last sorted value to last_pvt,
// then from last_pvt to previous last_pvt
/*
void	psw_qcksrt_B(t_game *game, size_t high, size_t low)
{
	size_t	med;
	size_t	to_sort;

	if (high - low <= 3)
		return ;
	med = low + (high - last_pvt) / 2;
	to_sort = (high - low) / 2 + 1;
	while (STK_B[high--].key != low)
	{
		edge_srt(game, B, med);
		if (STK_A[TOP_A].key == med)
		{
			buf_inst(game, PB);
			to_sort--;
			if (to_sort > 0 && to_sort != (high - low) / 2)
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
/*
void	psw_sort_B(t_game *game, size_t high, size_t low)
{
	if (high - low <= 15)
		// SELECTION SORT
	else
		psw_qcksrt_B(game, high, low);
}
*/

size_t	psw_find_key(t_game *game, t_mode stk, size_t key_to_find)
{
	size_t	i;
	t_val	*ptr;
	size_t	load;

	i = 0;
	if (stk == A)
	{
		ptr = STK_A;
		load = LOAD_A;
	}
	else
	{
		ptr = STK_B;
		load = LOAD_B;
	}
	while (ptr[i].key != key_to_find && i < load)
		i++;
	return (i);
}

void	psw_insersrt_A(t_game *game, size_t start, size_t end)
{
	size_t	nxt_key;
	size_t	i;

	i = 0;
	while (LOAD_A > 3 && nxt_key != end)
	{
		nxt_key = start + i;
		while (STK_A[TOP_A].key != nxt_key)
		{
			if (psw_find_key(game, A, nxt_key) >=  LOAD_A / 2 + 1)
				rot(game, A_INS);
			else
				rrot(game, A);
		}
		buf_inst(game, PB);
		i++;
	}
}

void	psw_qcksrt_A(t_game *game, size_t low, size_t high)
{
	size_t	to_sort;

	to_sort = (high - low) / 2 + 1;
	if (high - low <= 15)
		return psw_insersrt_A(game, low, high);
	while (to_sort && LOAD_A > 3) 
	{
		edge_srt(game, A, MED);
		if (STK_A[TOP_A].key <= MED)
		{
			buf_inst(game, PB);
			to_sort--;
			if (STK_B[TOP_B].key == MED && to_sort > 1)
				rot(game, B);
		}
		else
			rot(game, A);
	}
	if (STK_B[0].key == MED)
		rrot(game, B);
//	vctr_push(game->pvt, MED);
	psw_qcksrt_A(game, MED + 1, high);
}

void	psw_qcksrt_init(t_game *game, size_t low, size_t high)
{
	size_t	to_sort;
	_Bool	higher_than_med_on_stack;

	if (high - low <= 3)
		return ;
	to_sort = (high - low) / 2 + 1;
	higher_than_med_on_stack = 0;
	while (to_sort && LOAD_A > 3) 
	{
		edge_srt(game, START, MED);
		if (STK_A[TOP_A].key <= MED)
		{
			buf_inst(game, PB);
			if (!higher_than_med_on_stack && STK_B[TOP_B].key > MED / 2)
				higher_than_med_on_stack = 1;
			else if (higher_than_med_on_stack && STK_B[TOP_B].key <= MED / 2)
				rot(game, B);
			to_sort--;
		}
		else
			rot(game, A);
	}
//	vctr_push(game->info.pvt, &MED);
	psw_qcksrt_A(game, MED + 1, high);
}

void	psw_solver(t_game *game)
{
	if (game->info.mon)
		psw_monitor(game);
	if (LOAD_A <= 20)
		psw_qcksrt_A(game, 0, TOP_A);
	else
		psw_qcksrt_init(game, 0, TOP_A);
//	edge_srt(game, A_3, 0); //sort 3 last values in A
//	if (LOAD_B)
//		psw_sort_B(game, STK_A[TOP_A].key - 1, PVT[LST_PVT]);
//	depiler B en terminant le tri
	buf_inst(game, END);
}
