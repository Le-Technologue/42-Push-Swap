/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:39:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/27 17:54:11 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TENTION
#include "libft.h"
#include "psw_inst.h"
#include "psw_opti.h"
#include "psw_probes.h"
#include "psw_five_srt.h"
#include "psw_algo.h"
#include "psw_monitor.h"

size_t	med_srt_tops(t_game *game, t_mode step, size_t med)
{
	size_t	moves;

	moves = 0;
	if (LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[TOP_A - 1].key)
	{
		if (step == START
			&& ((STK_A[TOP_A].key > med && STK_A[TOP_A - 1].key > med)
			|| ((STK_A[TOP_A].key > med / 2 && STK_A[TOP_A - 1].key > med / 2)
				&& (STK_A[TOP_A].key <= med && STK_A[TOP_A - 1].key <= med))
			|| (STK_B[TOP_B].key <= med / 2
				&& (STK_A[TOP_A].key <= med && STK_A[TOP_A - 1].key <= med))))
			moves += swp(game, A);
		else if (step <= A
			&& ((STK_A[TOP_A].key < med && STK_A[TOP_A - 1].key < med)
			|| (STK_A[TOP_A].key > med && STK_A[TOP_A - 1].key > med)))
			moves += swp(game, A);
	}
	if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[TOP_B - 1].key)
	{
		if (step == A && STK_B[TOP_B - 1].key != med)
			moves += swp(game, B);
		else if (step != A)
			moves += swp(game, B);
	}
	return (moves);
}

size_t	srt_bottoms(t_game *game, size_t med)
{
	size_t	moves;

	moves = 0;
	if (PRV_MOV != RA && LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[0].key
			&& (STK_A[TOP_A].key <= med && STK_A[0].key <= med))
		moves += rrot(game, A);
	if (PRV_MOV != RB && LOAD_B >= 2 && STK_B[0].key != med
			&& STK_B[TOP_B].key < STK_B[0].key)
		moves += rrot(game, B);
	if (PRV_MOV != RRA && LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[0].key
			&& (STK_A[TOP_A].key > med && STK_A[0].key > med))
		moves += rot(game, A);
	if (PRV_MOV != RRB && LOAD_B >= 2 && STK_B[0].key != med
			&& STK_B[TOP_B].key < STK_B[0].key)
		moves += rot(game, B);
	return (moves);
}

size_t	srt_next_to_tops(t_game *game, size_t med)
{
	size_t	moves;

	moves = 0;
	if (PRV_MOV != RA && LOAD_A >= 3 && STK_A[0].key == STK_A[TOP_A].key + 1
			&& (STK_A[TOP_A].key <= med && STK_A[0].key <= med))
		moves += rrot(game, A);
	if (PRV_MOV != RB && LOAD_B >= 3 && STK_B[0].key == STK_B[TOP_B].key - 1
			&& (STK_A[TOP_A].key >= med && STK_A[0].key >= med))
		moves += rrot(game, B);
	return (moves);
}

void	edge_srt(t_game *game, t_mode step, size_t med)
{
	size_t	moves;

	while (1)
	{
		moves = 0;
		moves += srt_bottoms(game, med);
		moves += med_srt_tops(game, step, med);
		moves += srt_next_to_tops(game, med);
		moves += med_srt_tops(game, step, med);
		if (!moves)
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
	med_srt_tops(game, step, med, loop);
}

void	edge_srt(t_game *game, t_mode step, size_t med)
{
	_Bool loop;

	while ((LOAD_A > 1 && (STK_A[TOP_A].key > STK_A[TOP_A - 1].key))
			|| (LOAD_B > 1 && (STK_B[TOP_B].key < STK_B[TOP_B - 1].key)))
	{
		loop = 1;
		med_srt_tops(game, step, med, &loop);
		srt_bottoms(game, step, med, &loop);
		med_srt_tops(game, step, med, &loop);
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
			psh(game, B);
			to_sort--;
			if (to_sort > 0 && to_sort != (high - low) / 2)
				rot(game, B);
		}
		else if (STK_A[TOP_A].key < med)
		{
			psh(game, B);
			to_sort--;
		}
		else
			rot(game, A);
	}
	if (STK_B[0].key == med)
		rrot(game, B);
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

void	psw_inssrt_B(t_game *game, size_t high, size_t low)
{
	size_t	nxt_key;
	size_t	i;

	i = 0;
	while (LOAD_B > 3 && nxt_key != low)
	{
		nxt_key = high - i;
		while (STK_B[TOP_B].key != nxt_key)
		{
			if (psw_find_key(game, B, nxt_key) >=  LOAD_B / 2 + 1)
				rot(game, B_INS);
			else
				rrot(game, B);
		}
		psh(game, B);
		i++;
	}
}
*/

size_t	psw_key_location(t_val *ptr, size_t load, size_t key_to_find)
{
	size_t	i;

	i = 0;
	while (ptr[i].key != key_to_find && i <= load / 2 + 1)
		i++;
	return (i);
}

void	psw_ftch_key(t_game *game, t_stk *ptr, t_mode step, size_t key_to_fetch)
{
	size_t	nxt_key_to_fetch;

	if (step <= A)
		nxt_key_to_fetch = key_to_fetch + 1;
	else
		nxt_key_to_fetch = key_to_fetch - 1;
	if (psw_key_location(ptr->stk, ptr->load, key_to_fetch) >= ptr->load / 2 + 1)
	{
		while (ptr->stk[ptr->load - 1].key != key_to_fetch)
		{
			if (ptr->stk[ptr->load - 1].key == nxt_key_to_fetch)
				psh(game, step);
			rot(game, step);
		}
	}
	else
	{
		while (ptr->stk[ptr->load - 1].key != key_to_fetch)
		{
			if (ptr->stk[ptr->load - 1].key == nxt_key_to_fetch)
				psh(game, step);
			rrot(game, step);
		}
	}
}

void	psw_inssrt(t_game *game, t_mode step, size_t key_to_sort)
{
	t_stk	*ptr;

	if (step <= A)
		ptr = &game->a;
	else
		ptr = &game->b;
	psw_ftch_key(game, ptr, step, key_to_sort);
}

void	psw_inssrt_B(t_game *game, size_t high, size_t low)//, size_t prv_pvt_idx)
{
	size_t	nxt_key;
	size_t	i;

	i = 0;
	nxt_key = high;
	while (LOAD_B > 5 && !chk_B(game) && nxt_key > low)
	{
		nxt_key = high - i;
		psw_inssrt(game, B_INS, nxt_key);
		psh(game, B_INS);
		i++;
		srt_tops(game);
		if (STK_A[TOP_A].key == nxt_key - 1)
			i++;
	}
}

void	psw_inssrt_A(t_game *game, size_t low, size_t high)
{
	size_t	nxt_key;
	size_t	i;

	i = 0;
	nxt_key = low;
	while (LOAD_A > 5 && !chk_A(game) && nxt_key < high)
	{
		nxt_key = low + i;
		psw_inssrt(game, A_INS, nxt_key);
		i++;
		if (chk_A(game))
			break ;
		psh(game, A_INS);
		srt_tops(game);
		if (STK_B[TOP_B].key == nxt_key + 1)
			i++;
	}
	if (!chk_A(game) && LOAD_A <= 5)
		five_srt(game);
	while (i--)
		psh(game, A_INS);
}
/*
void	psw_inssrt_A(t_game *game, size_t low, size_t high)
{
	size_t	nxt_key;
	size_t	i;

	i = 0;
	nxt_key = low;
	while (nxt_key < high && !chk_A(game))
	{
		nxt_key = low + i;
		if (STK_A[TOP_A].key == nxt_key + 1 && nxt_key + 1 < high)
			psh(game, B);
		while (STK_A[TOP_A].key != nxt_key && !chk_A(game))
		{
			if (psw_find_key(game, A, nxt_key) >= LOAD_A / 2 + 1)
				rot(game, A_INS);
			else
				rrot(game, A_INS);
			med_srt_tops(game, A_INS, MED);
			if (STK_A[TOP_A].key == nxt_key + 1 && nxt_key + 1 < high)
				psh(game, B);
		}
		if (chk_A(game))
			break ;
		psh(game, B);
		med_srt_tops(game, A_INS, MED);
		i++;
		if (STK_B[TOP_B].key == nxt_key + 1)
			i++;
	}
	five_srt(game);
	while (i--)
		psh(game, A);
}
*/

void	psw_qcksrt_B(t_game *game, size_t high, size_t low)
{
//	size_t	high;
//	size_t	low;
//
//	high = PVT[prv_pvt_idx] - 1;
//	low = PVT[prv_pvt_idx - 1];
	size_t	to_sort;
	size_t	i;

	i = 0;
	to_sort = (high - low) / 2 + 1;
	if (INSSRT_THRESHOLD)
		return psw_inssrt_B(game, high, low);
	to_sort = (high - low) / 2 + 1;
	while (to_sort)
	{
		edge_srt(game, B, MED);
		if (STK_B[TOP_B].key >= MED)
		{
			psh(game, A);
			to_sort--;
			if (STK_A[TOP_A].key == MED && to_sort > 1)
				rot(game, A);
		}
		else
		{
			rot(game, B);
			i++;
		}
	if (STK_A[0].key == MED)
		rrot(game, B);
	}
	while (i--)
		rrot(game, B);
	psw_qcksrt_A(game, MED, high);
	psw_qcksrt_B(game, MED - 1, low);
}

void	psw_qcksrt_A(t_game *game, size_t low, size_t high)
{
	size_t	to_sort;

	to_sort = (high - low) / 2 + 1;
	vctr_push(game->info.pvt, &low);
	if (INSSRT_THRESHOLD)
		return psw_inssrt_A(game, low, high);
	while (to_sort) 
	{
		edge_srt(game, A, MED);
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
	if (STK_B[0].key == MED)
		rrot(game, B);
	if (STK_B[TOP_B - 1].key == MED)
		swp(game, B);
	psw_qcksrt_B(game, MED, low);
	psw_qcksrt_A(game, MED + 1, high);
}

void	psw_qcksrt_init(t_game *game, size_t low, size_t high)
{
	size_t	to_sort;
	size_t	half_med;

	half_med = MED / 2;
	vctr_push(game->info.pvt, &low);
	vctr_push(game->info.pvt, &half_med);
	if (QCKSRT_THRESHOLD)
		return psw_qcksrt_A(game, low, high);
	to_sort = (high - low) / 2 + 1;
	while (to_sort) 
	{
		edge_srt(game, START, MED);
		if (STK_A[TOP_A].key <= MED)
		{
			psh(game, B);
			if (STK_B[TOP_B - 1].key > half_med && STK_B[TOP_B].key <= half_med)
				rot(game, B);
			to_sort--;
		}
		else
			rot(game, A);
	}
	edge_srt(game, START, MED);
	psw_qcksrt_B(game, MED, half_med + 1);
	psw_qcksrt_B(game, half_med, low);
	psw_qcksrt_A(game, MED + 1, high);
}

void	psw_solver(t_game *game)
{
	if (game->info.mon) // MONITORING
		psw_monitor(game);
	psw_qcksrt_init(game, 0, TOP_A - 5);
//	edge_srt(game, A_3, TOP_A / 2); //sort 3 last values in A
	if (LOAD_B)
		psw_inssrt_B(game, TOP_B, 0);
//		psw_qcksort_B(game, PVT[LST_PVT] - 1, PVT[LST_PVT - 1]);
//	five_srt(game);
//	depiler B en terminant le tri
	buf_inst(game, END);
}
