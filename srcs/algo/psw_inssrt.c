/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inssrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:52:24 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/25 09:59:50 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst_mngr.h"
#include "psw_probes.h"
#include "psw_five_srt.h"
#include "psw_inssrt.h"

static void	psw_ftch_key(t_game *game, t_step step, size_t sought, size_t nxt)
{
	t_stk	*ptr;
	size_t	queried_idx;

	ptr = stk_ptr(game, step);
	queried_idx = psw_srch_key(ptr, ptr->load, sought);
	if (ptr->stk[ptr->load - 1].key == nxt)
		psh(game, step);
	if (queried_idx >= ptr->load / 2)
	{
		while (ptr->stk[ptr->load - 1].key != sought)
		{
			rot(game, step);
			if (ptr->stk[ptr->load - 1].key == nxt)
				psh(game, step);
		}
	}
	else
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
	while (LOAD_B && STK_A[TOP_A].key > low)
	{
		sought_key = high - pushes;
		if (sought_key <= low)
			psw_ftch_key(game, B_INS, sought_key, GAME_QTY);
		else
			psw_ftch_key(game, B_INS, sought_key, sought_key - 1);
		psh(game, B_INS);
		pushes++;
		three_srt(game, low, high);
		if (STK_A[TOP_A].key == sought_key - 1)
			pushes++;
	}
}

void	inssrt_a(t_game *game, size_t low, size_t high)
{
	size_t	sought_key;
	size_t	pushes;

	pushes = 0;
	while (LOAD_A > 5 && STK_B[TOP_B].key <= high - 1
		&& !sorted(game, A, TOP_A - RMNG))
	{
		sought_key = low + pushes;
		if (sought_key >= high)
			psw_ftch_key(game, A_INS, sought_key, GAME_QTY);
		else
			psw_ftch_key(game, A_INS, sought_key, sought_key + 1);
		if (STK_A[TOP_A].key < high)
		{
			psh(game, A_INS);
			pushes++;
		}
		three_srt(game, low, high);
		if (STK_B[TOP_B].key == sought_key + 1)
			pushes++;
	}
	if (LOAD_A <= 5 && !sorted(game, A, 0))
		five_srt_a(game, low + pushes, high);
	while (pushes--)
		psh(game, B_INS);
}

void	twin_inssrt(t_game *game, size_t low, size_t high)
{
	inssrt_a(game, MED + 1, high);
	inssrt_b(game, MED, low);
}
