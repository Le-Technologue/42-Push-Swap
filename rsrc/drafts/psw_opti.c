/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_opti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:51:07 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/14 14:59:41 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"
#include "psw_inst_mngr.h"
#include "psw_opti.h"

size_t	med_srt_tops(t_game *game, t_mode step, size_t med)
{
	size_t	moves;

	moves = 0;
	if (LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[TOP_A - 1].key)
	{
		if (step == A_SPLT
			&& ((STK_A[TOP_A].key > med && STK_A[TOP_A - 1].key > med)
			|| ((STK_A[TOP_A].key > med / 2 && STK_A[TOP_A - 1].key > med / 2)
				&& (STK_A[TOP_A].key <= med && STK_A[TOP_A - 1].key <= med))
			|| (STK_B[TOP_B].key <= med / 2
				&& (STK_A[TOP_A].key <= med && STK_A[TOP_A - 1].key <= med))))
			moves += swp(game, A_SEC);
		else if (step <= A
			&& ((STK_A[TOP_A].key < med && STK_A[TOP_A - 1].key < med)
			|| (STK_A[TOP_A].key > med && STK_A[TOP_A - 1].key > med)))
			moves += swp(game, A_SEC);
	}
	if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[TOP_B - 1].key)
	{
		if (step == A && STK_B[TOP_B - 1].key != med)
			moves += swp(game, B_SEC);
		else if (step != A)
			moves += swp(game, B_SEC);
	}
	return (moves);
}

size_t	srt_bottoms(t_game *game, size_t med)
{
	size_t	moves;

	moves = 0;
	if (PRV_MOV != RA && LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[0].key
			&& (STK_A[TOP_A].key <= med && STK_A[0].key <= med))
		moves += rrot(game, A_SEC);
	if (PRV_MOV != RB && LOAD_B >= 2 && STK_B[0].key != med
			&& STK_B[TOP_B].key < STK_B[0].key)
		moves += rrot(game, B_SEC);
	if (PRV_MOV != RRA && LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[0].key
			&& (STK_A[TOP_A].key > med && STK_A[0].key > med))
		moves += rot(game, A_SEC);
	if (PRV_MOV != RRB && LOAD_B >= 2 && STK_B[0].key != med
			&& STK_B[TOP_B].key < STK_B[0].key)
		moves += rot(game, B_SEC);
	return (moves);
}

size_t	srt_next_to_tops(t_game *game, size_t med)
{
	size_t	moves;

	moves = 0;
	if (PRV_MOV != RA && LOAD_A >= 3 && STK_A[0].key == STK_A[TOP_A].key + 1
			&& (STK_A[TOP_A].key <= med && STK_A[0].key <= med))
		moves += rrot(game, A_SEC);
	if (PRV_MOV != RB && LOAD_B >= 3 && STK_B[0].key == STK_B[TOP_B].key - 1
			&& (STK_A[TOP_A].key >= med && STK_A[0].key >= med))
		moves += rrot(game, B_SEC);
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
} // Drafts follow

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
		rrot(game, A_SEC);
		*loop = 0;
	}
	if (PRV_MOV != RB && STK_B[0].key != med // && step != A 
			&& LOAD_B >= 3 && STK_B[TOP_B].key < STK_B[0].key
			&& STK_B[TOP_B].key > STK_B[TOP_B - 1].key)
	{
		rrot(game, B_SEC);
		*loop = 0;
	}
	if (PRV_MOV != RRA && LOAD_A >= 3 && STK_A[TOP_A].key > STK_A[0].key
			&& (STK_A[TOP_A].key >= med && STK_A[0].key >= med))
	{
		rot(game, A_SEC);
		*loop = 0;
	}
	if (PRV_MOV != RRB && STK_B[0].key != med // && step != A
			&& LOAD_B >= 3 && STK_B[TOP_B].key < STK_B[0].key)
	{
		rot(game, B_SEC);
		*loop = 0;
	}
}

void	srt_next_to_top(t_game *game, t_mode step, size_t med, _Bool *loop)
{
	if (PRV_MOV != RA && LOAD_A >= 3 && STK_A[0].key == STK_A[TOP_A].key + 1
			&& (STK_A[TOP_A].key <= med && STK_A[0].key <= med))
	{
		rrot(game, A_SEC);
		*loop = 0;
	}
	if (PRV_MOV != RB && LOAD_B >= 3 && STK_B[0].key == STK_B[TOP_B].key - 1
			&& (STK_A[TOP_A].key >= med && STK_A[0].key >= med))
	{
		rrot(game, B_SEC);
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
