/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_opti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:51:07 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/24 13:56:59 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_opti.h"
#include "psw_inst.h"

size_t	psh(t_game *game, t_mode mode)
{
	if (mode == A && LOAD_B && PRV_MOV != PB)
	{
		buf_inst(game, PA);
		return (1);
	}
	if (mode == B && LOAD_A && PRV_MOV != PA)
	{
		buf_inst(game, PB);
		return (1);
	}
	return (0);
}

size_t	swp(t_game *game, t_mode mode)
{
	if (mode == A)
	{
		if (LOAD_A == 2 && PRV_MOV == RB)
			buf_inst(game, RA);
		else if (LOAD_A == 2 && PRV_MOV == RRB)
			buf_inst(game, RRA);
		else if (PRV_MOV != SA)
			buf_inst(game, SA);
		else
			return (0);
	}
	if (mode == B)
	{
		if (LOAD_B == 2 && PRV_MOV == RA)
			buf_inst(game, RB);
		else if (LOAD_B == 2 && PRV_MOV == RRA)
			buf_inst(game, RRB);
		else if (PRV_MOV != SB)
			buf_inst(game, SB);
		else
			return (0);
	}
	return (1);
}

size_t	rot(t_game *game, t_mode mode)
{
	if (mode <= A)
	{
		if ((LOAD_A == 2 || mode == A_INS) && PRV_MOV == SB)
			buf_inst(game, SA);
		else if (LOAD_B == 2 && PRV_MOV == RRB)
			buf_inst(game, RRA);
		else if (PRV_MOV != RRA)
			buf_inst(game, RA);
		else
			return (0);
	}
	else if (mode <= B)
	{
		if ((LOAD_B == 2 || mode == B_INS) && PRV_MOV == SA)
			buf_inst(game, SB);
		else if (LOAD_B == 2 && PRV_MOV == RRA)
			buf_inst(game, RRB);
		else if (PRV_MOV != RRB)
			buf_inst(game, RB);
		else
			return (0);
	}
	return (1);
}

size_t	rrot(t_game *game, t_mode mode)
{
	if (mode == A)
	{
		if (LOAD_A == 2 && PRV_MOV == SB)
			buf_inst(game, SA);
		else if (LOAD_A == 2 && PRV_MOV == RB)
			buf_inst(game, RA);
		else if (PRV_MOV != RA)
			buf_inst(game, RRA);
		else
			return (0);
	}
	if (mode == B)
	{
		if (LOAD_B == 2 && PRV_MOV == SA)
			buf_inst(game, SB);
		else if (LOAD_B == 2 && PRV_MOV == RA)
			buf_inst(game, RB);
		else if (PRV_MOV != RB)
			buf_inst(game, RRB);
		else
			return (0);
	}
	return (1);
}
