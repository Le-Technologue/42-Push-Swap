/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_five_srt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:59:10 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/24 14:38:53 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "psw_opti.h"
# include "psw_probes.h"

size_t	srt_tops(t_game *game)
{
	size_t	moves;

	moves = 0;
	if (LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[TOP_A - 1].key)
		moves += swp(game, A);
	if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[TOP_B - 1].key)
		moves += swp(game, B);
	return (moves);
}

void	three_srt(t_game *game)
{
	size_t	moves;

	while (1)
	{
		moves = 0;
		if (LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[0].key
				&& STK_A[TOP_A].key < STK_A[TOP_A - 1].key)
			moves += rrot(game, A);
		if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[0].key
				&& STK_B[TOP_B].key > STK_B[TOP_B - 1].key)
			moves += rrot(game, B);
		if (LOAD_A >= 2 && STK_A[TOP_A].key > STK_A[0].key)
			moves += rot(game, A);
		if (LOAD_B >= 2 && STK_B[TOP_B].key < STK_B[0].key)
			moves += rot(game, B);
		moves += srt_tops(game);
		if (LOAD_A >= 3 && STK_A[0].key == STK_A[TOP_A].key + 1)
			moves += rrot(game, A);
		if (LOAD_B >= 3 && STK_B[0].key == STK_B[TOP_B].key - 1)
			moves += rrot(game, B);
		moves += srt_tops(game);
		if (!moves)
			break ;
	}
}

void	five_srt(t_game *game)
{
	int i;

	if (game->qty <= 3)
		return three_srt(game);
	if (STK_A[TOP_A].key == game->qty - 2)
	{
		rrot(game, A);
		three_srt(game);
		rrot(game, A);
	}
	i = 0;
	while (!chk_A(game) && i < 2)
	{
		three_srt(game);
		if (chk_A(game))
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
