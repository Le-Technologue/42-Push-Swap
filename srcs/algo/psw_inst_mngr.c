/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inst_mngr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 08:09:07 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/17 12:18:10 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"
#include "psw_inst_mngr.h"

size_t	psh(t_game *game, t_step step)
{
	if (game->b.load && (step == A || step == B_INS
			|| (step == A_SEC && game->info.prv_mov != PB)))
	{
		buf_inst(game, PA);
		return (1);
	}
	if (game->a.load && (step == B || step == A_INS
			|| (step == B_SEC && game->info.prv_mov != PA)))
	{
		buf_inst(game, PB);
		return (1);
	}
	return (0);
}

size_t	swp(t_game *game, t_step step)
{
	if (step <= A)
	{
		if (game->a.load == 2 && game->info.prv_mov == RB)
			buf_inst(game, RA);
		else if (game->a.load == 2 && game->info.prv_mov == RRB)
			buf_inst(game, RRA);
		else if (game->a.load >= 2
			&& (step != A_SEC || game->info.prv_mov != SA))
			buf_inst(game, SA);
		else
			return (0);
	}
	else if (step <= B)
	{
		if (game->b.load == 2 && game->info.prv_mov == RA)
			buf_inst(game, RB);
		else if (game->b.load == 2 && game->info.prv_mov == RRA)
			buf_inst(game, RRB);
		else if (game->b.load >= 2
			&& (step != B_SEC || game->info.prv_mov != SB))
			buf_inst(game, SB);
		else
			return (0);
	}
	return (1);
}

size_t	rot(t_game *game, t_step step)
{
	if (step <= A)
	{	
		if (game->a.load == 2 && game->info.prv_mov == SB)
			buf_inst(game, SA);
		else if (game->a.load == 2 && game->info.prv_mov == RRB)
			buf_inst(game, RRA);
		else if (game->a.load >= 2
			&& (step != A_SEC || game->info.prv_mov != RRA))
			buf_inst(game, RA);
		else
			return (0);
	}
	else if (step <= B)
	{
		if (game->b.load == 2 && game->info.prv_mov == SA)
			buf_inst(game, SB);
		else if (game->b.load == 2 && game->info.prv_mov == RRA)
			buf_inst(game, RRB);
		else if (game->b.load >= 2
			&& (step != B_SEC || game->info.prv_mov != RRB))
			buf_inst(game, RB);
		else
			return (0);
	}
	return (1);
}

size_t	rrot(t_game *game, t_step step)
{
	if (step <= A)
	{
		if (game->a.load == 2 && game->info.prv_mov == SB)
			buf_inst(game, SA);
		else if (game->a.load == 2 && game->info.prv_mov == RB)
			buf_inst(game, RA);
		else if (game->a.load >= 2
			&& (step != A_SEC || game->info.prv_mov != RA))
			buf_inst(game, RRA);
		else
			return (0);
	}
	else if (step <= B)
	{
		if (game->b.load == 2 && game->info.prv_mov == SA)
			buf_inst(game, SB);
		else if (game->b.load == 2 && game->info.prv_mov == RA)
			buf_inst(game, RB);
		else if (game->b.load >= 2
			&& (step != B_SEC || game->info.prv_mov != RB))
			buf_inst(game, RRB);
		else
			return (0);
	}
	return (1);
}
