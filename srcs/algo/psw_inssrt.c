/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inssrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:52:24 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/10 18:40:20 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst_mngr.h"
#include "psw_probes.h"
#include "psw_five_srt.h"
#include "psw_inssrt.h"

void	psw_ftch_key(t_game *game, t_mode step, size_t sought, size_t nxt)
{
	t_stk	*ptr;
	size_t	queried_idx;

	ptr = stk_ptr(game, step);
	queried_idx = psw_srch_key(ptr, ptr->load, sought);
	if (ptr->stk[ptr->load - 1].key == nxt)
		psh(game, step);
	if (queried_idx >= ptr->load / 2)// && queried_idx < ptr->load)
	{
		while (ptr->stk[ptr->load - 1].key != sought)
		{
			rot(game, step);
			if (ptr->stk[ptr->load - 1].key == nxt)
				psh(game, step);
		}
	}
	else// if (queried_idx < ptr->load / 2)
	{
		while (ptr->stk[ptr->load - 1].key != sought)
		{
			rrot(game, step);
			if (ptr->stk[ptr->load - 1].key == nxt)
				psh(game, step);
		}
	}
}

void	inssrt_b(t_game *game, size_t high, size_t low)
{
	size_t	sought_key;
	size_t	pushes;

	pushes = 0;
	while (LOAD_B > 5 && STK_A[TOP_A].key > low)// || pushes <= SET_QTY) && !sorted(game, B, TOP_B - RMNG))
	{
		sought_key = high - pushes;
//		if (sought_key <= low)
//			break ;
		if (sought_key <= low)
			psw_ftch_key(game, B_INS, sought_key, GAME_QTY);
		else
			psw_ftch_key(game, B_INS, sought_key, sought_key - 1);
		psh(game, B_INS);
		pushes++;
		three_srt(game);
		if (STK_A[TOP_A].key == sought_key - 1)
			pushes++;
	}
	if (LOAD_B <= 5)
		five_srt_B(game);
}

void	inssrt_a(t_game *game, size_t low, size_t high)
{
	size_t	sought_key;
	size_t	pushes;

	pushes = 0;
	while (LOAD_A > 5 && STK_B[TOP_B].key <= high - 1 && !sorted(game, A, TOP_A - RMNG))
	{
		sought_key = low + pushes;
		if (sought_key >= high)
			psw_ftch_key(game, A_INS, sought_key, GAME_QTY);
		else
			psw_ftch_key(game, A_INS, sought_key, sought_key + 1);
		if (STK_A[TOP_A].key < high)//TOP_A >= low && 
		{
			psh(game, A_INS);
			pushes++;
		}
//		if (sorted(game, A, TOP_A - RMNG, TOP_A))
//			break ;
		three_srt(game);
		if (STK_B[TOP_B].key == sought_key + 1)
			pushes++;
	}
	if (LOAD_A <= 5 && !sorted(game, A, 0))
		five_srt_A(game);
	while (pushes--)
		psh(game, B_INS);
}

void	twin_inssrt(t_game *game, size_t low, size_t high)
{
	inssrt_a(game, MED + 1, high);
	inssrt_b(game, MED, low);
} // Drafts follow :
/*
size_t	nxt_sought(t_mode step)
{
	if (step <= A)
		return (sought + 1);
	else
		return (sought - 1);
}

void	psw_inssrt(t_game *game, t_mode step, size_t key_to_sort)
{
	psw_ftch_key(game, stk_ptr(game, step), step, &key_to_sort);
}

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

*/
