/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_five_srt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:59:10 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/25 09:58:35 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst_mngr.h"
#include "psw_probes.h"

static size_t	srt_tops(t_game *game)
{
	size_t	moves;

	moves = 0;
	if (LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[TOP_A - 1].key)
		moves += swp(game, A_SEC);
	if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[TOP_B - 1].key)
		moves += swp(game, B_SEC);
	return (moves);
}

static size_t	srt_bottoms(t_game *game)
{
	size_t	moves;

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
	return (moves);
}

void	three_srt(t_game *game, size_t low, size_t high)
{
	size_t	moves;

	while (1)
	{
		moves = 0;
		if ((STK_A[TOP_A].key <= MED && STK_A[TOP_A - 1].key <= MED)
			|| (STK_A[TOP_A].key > MED && STK_A[TOP_A - 1].key > MED))
			moves += srt_tops(game);
		moves += srt_bottoms(game);
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

void	five_srt_a(t_game *game, size_t low, size_t high)
{
	int	i;

	if (LOAD_A <= 3)
		return (three_srt(game, low, high));
	i = 0;
	while (!sorted(game, A, 0) && i < 2)
	{
		three_srt(game, low, high);
		if (sorted(game, A, 0))
			break ;
		psh(game, B);
		i++;
	}
	while (i)
	{
		three_srt(game, low, high);
		psh(game, A);
		i--;
	}
	three_srt(game, low, high);
}
