/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inst_mngr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 08:09:07 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/03 12:49:25 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"
#include "psw_inst_mngr.h"

size_t	psh(t_game *game, t_mode mode)
{
	if (LOAD_B && (mode == A || mode == B_INS
		|| (mode == A_SEC && PRV_MOV != PB)))
	{
		buf_inst(game, PA);
		return (1);
	}
	if (LOAD_A && (mode == B || mode == A_INS
		|| (mode == B_SEC && PRV_MOV != PA)))
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
		else if (LOAD_A >= 2 && PRV_MOV != SA)
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
		else if (LOAD_B >= 2 && PRV_MOV != SB)
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
		if (mode == A_STOR)
			UNDR_A++;
		if (LOAD_A == 2 && PRV_MOV == SB)
			buf_inst(game, SA);
		else if (LOAD_A == 2 && PRV_MOV == RRB)
			buf_inst(game, RRA);
		else if (LOAD_A >= 2 && (mode != A_SEC || PRV_MOV != RRA))
			buf_inst(game, RA);
		else
			return (0);
	}
	else if (mode <= B)
	{
		if (mode == B_STOR)
			UNDR_B++;
		if (LOAD_B == 2 && PRV_MOV == SA)
			buf_inst(game, SB);
		else if (LOAD_B == 2 && PRV_MOV == RRA)
			buf_inst(game, RRB);
		else if (LOAD_B >= 2 && PRV_MOV != RRB)
			buf_inst(game, RB);
		else
			return (0);
	}
	return (1);
}

size_t	rrot(t_game *game, t_mode mode)
{
	if (mode <= A)
	{
		if (mode == A_STOR)
			UNDR_A--;
		if (LOAD_A == 2 && PRV_MOV == SB)
			buf_inst(game, SA);
		else if (LOAD_A == 2 && PRV_MOV == RB)
			buf_inst(game, RA);
		else if (LOAD_A >= 2 && (mode != A_SEC || PRV_MOV != RA))
			buf_inst(game, RRA);
		else
			return (0);
	}
	else if (mode <= B)
	{
		if (mode == B_STOR)
			UNDR_B--;
		if (LOAD_B == 2 && PRV_MOV == SA)
			buf_inst(game, SB);
		else if (LOAD_B == 2 && PRV_MOV == RA)
			buf_inst(game, RB);
		else if (LOAD_B >= 2 && PRV_MOV != RB)
			buf_inst(game, RRB);
		else
			return (0);
	}
	return (1);
}
