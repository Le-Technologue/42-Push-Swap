/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:39:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/10 18:06:15 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"
/*
void	psw_qcksrt(, size_t to_sort) //0 to med
{
	while (to_sort) 
	{
		if (game->a.stk[game->a.top] == game->info.med)
		{
			buf_inst(game, PB);
			buf_inst(game, RB);
			to_sort--;
		}
		else if (game->a.stk[game->a.top] < game->info.med)
			buf_inst(game, PB);
		else
			buf_inst(game, RA);
	}
	buf_inst(game, RRB);
}
*/
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
			&& game->info.qty > 2)
		buf_inst(game, RRA);
	if (game->b.stk[0].key == game->b.stk[game->b.top].key - 1
			&& game->info.qty > 2)
		buf_inst(game, RRB);
	if (game->a.stk[game->a.top].key < game->a.stk[game->a.top - 1].key
			&& game->a.stk[game->a.top - 1].key <= game->a.stk[0].key)
		return (CLEAR);
	return (ERROR);
}

void	psw_solver(t_game *game)
{
	while (srt_edges(game))
		;
	buf_inst(game, END);
}
