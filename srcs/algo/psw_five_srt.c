/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_five_srt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:59:10 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/24 16:05:59 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst_mngr.h"
#include "psw_probes.h"

static size_t	srt_tops(t_game *game)
{
	size_t	moves;

	moves = 0;
	if (game->a.load >= 2
		&& game->a.stk[game->a.load - 1].key
		> game->a.stk[game->a.load - 1 - 1].key)
		moves += swp(game, A_SEC);
	if (game->b.load >= 2
		&& game->b.stk[game->b.load - 1].key
		< game->b.stk[game->b.load - 1 - 1].key)
		moves += swp(game, B_SEC);
	return (moves);
}

static size_t	srt_bottoms(t_game *game)
{
	size_t	moves;

	moves = 0;
	if (game->a.load >= 2
		&& game->a.stk[game->a.load - 1].key > game->a.stk[0].key
		&& game->a.stk[game->a.load - 1].key
		< game->a.stk[game->a.load - 1 - 1].key)
		moves += rrot(game, A_SEC);
	if (game->b.load >= 2 && game->b.stk[game->b.load - 1].key
		< game->b.stk[0].key
		&& game->b.stk[game->b.load - 1].key
		> game->b.stk[game->b.load - 1 - 1].key)
		moves += rrot(game, B_SEC);
	if (game->a.load >= 2
		&& game->a.stk[game->a.load - 1].key > game->a.stk[0].key)
		moves += rot(game, A_SEC);
	if (game->b.load >= 2
		&& game->b.stk[game->b.load - 1].key < game->b.stk[0].key)
		moves += rot(game, B_SEC);
	return (moves);
}

void	three_srt(t_game *game, size_t low, size_t high)
{
	size_t	moves;
	size_t	med;

	med = low + (high - low) / 2;
	while (1)
	{
		moves = 0;
		if ((game->a.stk[game->a.load - 1].key <= med
				&& game->a.stk[game->a.load - 1 - 1].key <= med)
			|| (game->a.stk[game->a.load - 1].key > med
				&& game->a.stk[game->a.load - 1 - 1].key > med))
			moves += srt_tops(game);
		moves += srt_bottoms(game);
		moves += srt_tops(game);
		if (game->a.load >= 3
			&& game->a.stk[0].key == game->a.stk[game->a.load - 1].key + 1)
			moves += rrot(game, A_SEC);
		if (game->b.load >= 3
			&& game->b.stk[0].key == game->b.stk[game->b.load - 1].key - 1)
			moves += rrot(game, B_SEC);
		moves += srt_tops(game);
		if (!moves)
			break ;
	}
}

void	five_srt_a(t_game *game, size_t low, size_t high)
{
	int	i;

	if (game->a.load <= 3)
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
