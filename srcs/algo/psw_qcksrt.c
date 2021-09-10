/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_qcksrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:00:16 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/10 10:41:27 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst_mngr.h"
#include "psw_inssrt.h"
#include "psw_mrgsrt.h"
#include "psw_qcksrt.h"
#include "psw_opti.h"

void	last_srt_a(t_game *game, size_t low, size_t high)
{
	if (INSSRT_THRESHOLD)
		inssrt_a(game, low, high);
	else
		qcksrt_a(game, low, high, LAST);
	if (high - low > 30)
		qcksrt_b(game, MED, low, LAST);
}

void	last_srt_b(t_game *game, size_t high, size_t low)
{
	if (INSSRT_THRESHOLD)
		inssrt_b(game, low, high);
	else
		qcksrt_b(game, high, low, LAST);
	if (high - low > 30)
		qcksrt_b(game, MED, low, LAST);
}

void	qcksrt_b(t_game *game, size_t high, size_t low, t_mode step) //edge_srt?
{
	size_t	over_a;

	if (step != LAST && LASTSRT_THRESHOLD)
		return (last_srt_b(game, high, low));
	over_a = 0;
	while (over_a < H_HLFMED - MED)
	{
		if (STK_B[TOP_B].key > MED)
		{
			psh(game, A);
			if (STK_A[TOP_A].key <= H_HLFMED)
				rot(game, A_STOR);
			else
				over_a++;
		}
		else
			rot(game, B);
	}
	mrg_to_a(game, high, MED + 1, TO_SORT_OVER_MED - over_a - UNDR_A); // OUCH
	if (TWIN_INSSRT_THRSHLD)
		twin_inssrt(game, low, high);
	else
		qcksrt_a(game, MED + 1, high, step);
	if (step != LAST && LOAD_B)
		qcksrt_b(game, MED, low, B);
}

void	qcksrt_a(t_game *game, size_t low, size_t high, t_mode step)
{
	size_t	over_b;

	if (step != LAST && LASTSRT_THRESHOLD)
		return (last_srt_a(game, low, high));
	over_b = 0;
	while (over_b < MED - L_HLFMED) 
	{
//		edge_srt(game, A_SPLT, MED); //should account for stored values now
		if (STK_A[TOP_A].key <= MED)
		{
			psh(game, B);
			if (STK_B[TOP_B].key > L_HLFMED)
				rot(game, B_STOR);
			else
				over_b++;
		}
		else
			rot(game, A);
	}
//	edge_srt(game, A_SPLT, MED); //should account for stored values now
	mrg_to_b(game, low, MED, TO_SORT_UNDR_MED + 1 - over_b - UNDR_B);
	if (TWIN_INSSRT_THRSHLD)
		twin_inssrt(game, low, high);
	else
		qcksrt_a(game, MED + 1, high, step);
	if (step != LAST && LOAD_B)
		qcksrt_b(game, MED, low, B);
}

void	psw_qcksrt_init(t_game *game, size_t low, size_t high)
{
	size_t	to_sort;

	if (LASTSRT_THRESHOLD)
		return (last_srt_a(game, low, high));
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
}// Drafts follow :
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
