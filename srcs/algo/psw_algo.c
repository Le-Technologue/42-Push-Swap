/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:39:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/13 13:25:22 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"
#include "psw_monitor.h"

t_error	srt_edges(t_game *game)
{
	if (game->a.stk[game->a.top].key > game->a.stk[0].key
			&& game->a.stk[game->a.top].key < game->a.stk[game->a.top - 1].key)
		buf_inst(game, RRA);
	if (game->b.stk[game->b.top].key < game->b.stk[0].key
			&& game->b.stk[game->b.top].key > game->b.stk[game->b.top - 1].key)
		buf_inst(game, RRB);
	if (game->a.stk[game->a.top].key > game->a.stk[0].key)
		buf_inst(game, RA);
	if (game->b.stk[game->b.top].key < game->b.stk[0].key)
		buf_inst(game, RB);
	if (game->a.stk[game->a.top].key > game->a.stk[game->a.top - 1].key)
		buf_inst(game, SA);
	if (game->b.stk[game->b.top].key < game->b.stk[game->b.top - 1].key)
		buf_inst(game, SB);
	if (game->a.stk[0].key == game->a.stk[game->a.top].key + 1
			&& game->qty > 2)
		buf_inst(game, RRA);
	if (game->b.stk[0].key == game->b.stk[game->b.top].key - 1
			&& game->qty > 2)
		buf_inst(game, RRB);
	if (game->a.stk[game->a.top].key > game->a.stk[game->a.top - 1].key)
		buf_inst(game, SA);
	if (game->b.stk[game->b.top].key < game->b.stk[game->b.top - 1].key)
		buf_inst(game, SB);
	if (game->a.stk[game->a.top].key < game->a.stk[game->a.top - 1].key
			&& game->a.stk[game->a.top - 1].key <= game->a.stk[0].key)
		return (CLEAR);
	return (ERROR);
}

void	psw_qcksrt(t_game *game, size_t start, size_t end)
{
	size_t	med;
	size_t	to_sort;

	if (start >= end)
		return ;
	med = start + (end - start) / 2;
	to_sort = med + 1;
	while (to_sort) 
	{
		if (game->a.stk[game->a.top].key == med)
		{
			buf_inst(game, PB);
			buf_inst(game, RB);
		}
		else if (game->a.stk[game->a.top].key < med)
			buf_inst(game, PB);
		else
			buf_inst(game, RA);
		to_sort--;
	}
//	while (srt_edges(game))
//		;
	buf_inst(game, RRB);
//	psw_qcksrt(game, 0, med);
	psw_qcksrt(game, med + 1, end);
}

void	psw_solver(t_game *game)
{
	if (game->mon)
		psw_monitor(game, 0);
//	while (srt_edges(game))
//		;
//	psw_qcksrt(game, 0, game->qty - 1);
	srt_edges(game);
	buf_inst(game, END);
}
