/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_opti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:51:07 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/20 21:53:35 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_opti.h"

void	swp(t_game *game, char stk)
{
	if (stk == 'A')
	{
		if (LOAD_A == 2 && PRV_MOV == RB)
			buf_inst(game, RA);
		else if (LOAD_A == 2 && PRV_MOV == RRB)
			buf_inst(game, RRA);
		else
			buf_inst(game, SA);
	}
	if (stk == 'B')
	{
		if (LOAD_B == 2 && PRV_MOV == RA)
			buf_inst(game, RB);
		else if (LOAD_B == 2 && PRV_MOV == RRA)
			buf_inst(game, RRB);
		else
			buf_inst(game, SB);
	}
}

void	rot(t_game *game, char stk)
{
	if (stk == 'A')
	{
		if (LOAD_A == 2 && PRV_MOV == SB)
			buf_inst(game, SA);
		else if (LOAD_A == 2 && PRV_MOV == RRB)
			buf_inst(game, RRA);
		else
			buf_inst(game, RA);
	}
	if (stk == 'B')
	{
		if (LOAD_B == 2 && PRV_MOV == SA)
			buf_inst(game, SB);
		else if (LOAD_B == 2 && PRV_MOV == RRA)
			buf_inst(game, RRB);
		else
			buf_inst(game, RB);
	}
}

void	rrot(t_game *game, char stk)
{
	if (stk == 'A')
	{
		if (LOAD_A == 2 && PRV_MOV == SB)
			buf_inst(game, SA);
		else if (LOAD_A == 2 && PRV_MOV == RB)
			buf_inst(game, RA);
		else
			buf_inst(game, RRA);
	}
	if (stk == 'B')
	{
		if (LOAD_B == 2 && PRV_MOV == SA)
			buf_inst(game, SB);
		else if (LOAD_B == 2 && PRV_MOV == RA)
			buf_inst(game, RB);
		else
			buf_inst(game, RRB);
	}
}
