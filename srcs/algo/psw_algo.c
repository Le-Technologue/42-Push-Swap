/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:39:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/08 22:16:19 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TENTION
#include "libft.h"
#include "psw_inst.h"
#include "psw_probes.h"
#include "psw_inst_mngr.h"
#include "psw_five_srt.h"
#include "psw_opti.h"
#include "psw_algo.h"
#include "psw_monitor.h"

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

void	psw_ftch_key(t_game *game, t_stk *ptr, t_mode step, size_t sought)
{
	size_t	queried_idx;
	size_t	nxt;

	if (step <= A)
		nxt = sought + 1;
	else
		nxt = sought - 1;
	queried_idx = psw_srch_key(ptr, ptr->load, sought);
	if (queried_idx >= ptr->load / 2 && queried_idx < ptr->load)
	{
		while (ptr->stk[ptr->load - 1].key != sought)
		{
			if (ptr->stk[ptr->load - 1].key == nxt)
				psh(game, step);
			rot(game, step);
		}
	}
	else if (queried_idx < ptr->load / 2)
	{
		while (ptr->stk[ptr->load - 1].key != sought)
		{
			if (ptr->stk[ptr->load - 1].key == nxt)
				psh(game, step);
			rrot(game, step);
		}
	}
}

/*
void	psw_inssrt(t_game *game, t_mode step, size_t key_to_sort)
{
	psw_ftch_key(game, stk_ptr(game, step), step, &key_to_sort);
}
*/

void	inssrt_b(t_game *game, size_t high, size_t low)//, size_t prv_pvt_idx)
{
	size_t	sought_key;
	size_t	pushes;

	pushes = 0;
	while (LOAD_B > 5 && !sorted(game, B, TOP_B - RMNG))
	{
		sought_key = high - pushes;
		if (sought_key <= low)
			break ;
		psw_ftch_key(game, &game->b, B_INS, sought_key);
		pushes++;
		psh(game, B_INS);
		srt_top_A(game);
		if (STK_A[TOP_A].key == sought_key - 1)
			pushes++;
		if (!sorted(game, B, 0) && LOAD_B <= 5)
			five_srt_B(game);
	}
}

void	inssrt_a(t_game *game, size_t low, size_t high)
{
	size_t	sought_key;
	size_t	pushes;

	pushes = 0;
	while (LOAD_A > 5 && pushes < SET_QTY && !sorted(game, A, TOP_A - RMNG))
	{
		sought_key = low + pushes;
		if (sought_key > high)
			break ;
		psw_ftch_key(game, &game->a, A_INS, sought_key);
		if (TOP_A >= low && TOP_A < high)
		{
			psh(game, A_INS);
			pushes++;
		}
//		if (sorted(game, A, TOP_A - RMNG, TOP_A))
//			break ;
		srt_top_B(game);
		if (STK_B[TOP_B].key == sought_key + 1)
			pushes++;
	}
	if (LOAD_A <= 5 && !sorted(game, A, 0))
		five_srt_A(game);
	while (pushes--)
		psh(game, B_INS);
}
/*
void	inssrt_a(t_game *game, size_t low, size_t high)
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
		return inssrt_b(game, high, low);
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
		return inssrt_a(game, low, high);
	while (to_sort) 
	{
//		edge_srt(game, A, MED);
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
//	edge_srt(game, A, MED);
	psw_qcksrt_B(game, MED, low);
	psw_qcksrt_A(game, MED + 1, high);
}
*/
void	mrg_to_b(t_game *game, size_t low, size_t high)
{
	size_t	i;

	i = 0;
	while (UNDR_B)
	{
		while (UNDR_B + i <= high - low
				&& STK_A[TOP_A].key > high && STK_A[TOP_A].key < low)
			rot(game, A_STOR);
		if (STK_B[0].key > STK_A[TOP_A].key || UNDR_B + i >= high - low)
			rrot(game, B_STOR);
		else
			psh(game, B);
		i++;
		//edge_srt/top_srt_A
	}
}


void	mrg_to_a(t_game *game, size_t low, size_t high)
{
	size_t	i;

	i = 0;
	while (UNDR_A)
	{
		while (UNDR_A + i <= high - low
				&& STK_B[TOP_B].key > high && STK_B[TOP_B].key < low)
			rot(game, B_STOR);
		if (STK_A[0].key > STK_B[TOP_B].key || UNDR_A + i >= high - low)
			rrot(game, A_STOR);
		else
			psh(game, A);
		i++;
		//edge_srt/top_srt_A
	}
}

void	final_srt_a(t_game *game, size_t low, size_t high)
{
	qcksrt_a(game, low, high, FINAL);
	qcksrt_b(game, MED, low, FINAL);
}

void	final_srt_b(t_game *game, size_t high, size_t low)
{
	qcksrt_b(game, high, low, FINAL);
	qcksrt_b(game, MED, low, FINAL);
}

void	qcksrt_a(t_game *game, size_t low, size_t high, t_mode step)
{
	size_t	to_sort;
	size_t	over_b;

	if (INSSRT_THRESHOLD)
		return (inssrt_a(game, low, high));
	if (step != FINAL && INSSRT_THRESHOLD * 4)
		return (final_srt_a(game, low, high));
	to_sort = (high - low) / 2;
	over_b = 0;
	while (to_sort && over_b < MED - L_HLFMED) 
	{
//		edge_srt(game, A_SPLT, MED);
		if (STK_A[TOP_A].key <= MED)
		{
			psh(game, B);
			if (STK_B[TOP_B].key > L_HLFMED)
				rot(game, B_STOR);
			else
				over_b++;
			to_sort--;
		}
		else
			rot(game, A_STOR);
	}
//	edge_srt(game, A_SPLT, MED);
	mrg_to_b(game, L_HLFMED + 1, MED);
	qcksrt_a(game, MED + 1, high, A);
//	if (step != FINAL && LOAD_B)
//		qcksrt_b(game, MED, low);
//	psw_qcksrt_init(game, low, MED - 1);
}

void	qcksrt_b(t_game *game, size_t high, size_t low, t_mode step)
{
	size_t	to_sort;
	size_t	over_a;

	if (INSSRT_THRESHOLD)
		return (inssrt_b(game, high, low));
	if (step != FINAL && INSSRT_THRESHOLD * 4)
		return (final_srt_b(game, low, high));
	over_a = 0;
	to_sort = (high - low) / 2;
	while (to_sort && over_a < high - H_HLFMED)
	{
//		edge_srt(game, START, MED);
		if (STK_B[TOP_B].key > MED)
		{
			psh(game, A);
			if (STK_A[TOP_A].key <= H_HLFMED)
				rot(game, A_STOR);
			else
				over_a++;
			to_sort--;
		}
		else
			rot(game, B_STOR);
	}
	mrg_to_a(game, MED + 1, H_HLFMED);
	qcksrt_a(game, MED + 1, high, B);
	if (step != FINAL && LOAD_B)
		qcksrt_b(game, MED, low, B);
}

void	psw_qcksrt_init(t_game *game, size_t low, size_t high)
{
	size_t	to_sort;

	if (INSSRT_THRESHOLD)
		return (inssrt_a(game, low, high));
	if (INSSRT_THRESHOLD * 4)
		return (final_srt_a(game, low, high));
	to_sort = (high - low) / 2 + 1;
	while (to_sort) 
	{
		edge_srt(game, A_SPLT, MED);
		if (STK_A[TOP_A].key <= MED)
		{
			psh(game, B);
			if (STK_B[TOP_B - 1].key > L_HLFMED && STK_B[TOP_B].key <= L_HLFMED)
				rot(game, B);
			to_sort--;
		}
		else
			rot(game, A);
	}
	edge_srt(game, A_SPLT, MED);
	qcksrt_a(game, MED + 1, high, A_SPLT);
	qcksrt_b(game, MED, L_HLFMED + 1, A_SPLT);
	qcksrt_b(game, L_HLFMED, low, A_SPLT);
}

/*
void	psw_qcksrt_init_A(t_game *game, size_t low, size_t high)
{
	size_t	to_sort;
	size_t	half_med;

	half_med = MED / 2;
	vctr_push(game->info.pvt, &low);
	vctr_push(game->info.pvt, &half_med);
	if (LOAD_A <= 5)
		return (five_srt_A(game));
//	if (QCKSRT_THRESHOLD)
//		return psw_qcksrt_A(game, low, high);
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
-	psw_qcksrt_B(game, MED, half_med + 1);
-	psw_qcksrt_B(game, half_med, low);
-	psw_qcksrt_A(game, MED + 1, high);
}
*/

void	psw_solver(t_game *game)
{
	if (game->info.mon) // MONITORING
		psw_monitor(game);
//	if (LOAD_A < 10)
		psw_qcksrt_init(game, 0, TOP_A);
//	else
//		psw_qcksrt_init(game, 0, TOP_A - 5);
//	edge_srt(game, A_3, TOP_A / 2); //sort 3 last values in A
	if (LOAD_B)
		inssrt_b(game, TOP_B, 0);
//		psw_qcksort_B(game, PVT[LST_PVT] - 1, PVT[LST_PVT - 1]);
//	five_srt(game);
//	depiler B en terminant le tri
	buf_inst(game, END);
}
