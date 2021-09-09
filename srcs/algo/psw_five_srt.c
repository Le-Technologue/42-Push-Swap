/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_five_srt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:59:10 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/09 16:40:04 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst_mngr.h"
#include "psw_probes.h"

size_t	srt_top_A(t_game *game)
{
	if (LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[TOP_A - 1].key)
		return(swp(game, A));
	return (0);
}

size_t	srt_top_B(t_game *game)
{
	if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[TOP_B - 1].key)
		return (swp(game, B));
	return (0);
}

size_t	srt_tops(t_game *game)
{
	size_t	moves;

	moves = 0;
	moves += srt_top_A(game);
	moves += srt_top_B(game);
	return (moves);
}

void	three_srt(t_game *game)
{
	size_t	moves; //SEC mode might create some troubles here...

	while (1)
	{
		moves = 0;
		if (LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[0].key
				&& STK_A[TOP_A].key < STK_A[TOP_A - 1].key)
			moves += rrot(game, A_SEC);
		if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[0].key
				&& STK_B[TOP_B].key > STK_B[TOP_B - 1].key)
			moves += rrot(game, B_SEC);
		if (LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[0].key)
			moves += rot(game, A_SEC);
		if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[0].key)
			moves += rot(game, B_SEC);
		moves += srt_tops(game);
		if (LOAD_A >= 3 && STK_A[0].key == STK_A[TOP_A].key + 1)
			moves += rrot(game, A_SEC);
		if (LOAD_B >= 3 && STK_B[0].key == STK_B[TOP_B].key - 1)
			moves += rrot(game, B_SEC);
		moves += srt_tops(game);
		if (!moves)
			break ;
	}
}

void	five_srt_B(t_game *game)
{
	int i;

	if (LOAD_B <= 3)
		return three_srt(game);
	if (STK_B[TOP_B].key == 1)
	{
		rrot(game, B);
		three_srt(game);
		rrot(game, B);
	}
	i = 0;
	while (!sorted(game, B, 0) && i < 2)
	{
		three_srt(game);
		if (sorted(game, B, 0))
			break ;
		psh(game, A);
		i++;
	}
	while (i)
	{
		three_srt(game);
		psh(game, B);
		i--;
	}
	three_srt(game);
}

void	five_srt_A(t_game *game)
{
	int i;

	if (LOAD_A <= 3)
		return three_srt(game);
	if (STK_A[TOP_A].key == GAME_QTY - 2)
	{
		rrot(game, A);
		three_srt(game);
		rrot(game, A);
	}
	i = 0;
	while (!sorted(game, A, 0) && i < 2)
	{
		three_srt(game);
		if (sorted(game, A, 0))
			break ;
		psh(game, B);
		i++;
	}
	while (i)
	{
		three_srt(game);
		psh(game, A);
		i--;
	}
	three_srt(game);
}
