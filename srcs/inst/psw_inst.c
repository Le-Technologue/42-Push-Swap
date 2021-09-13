/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:43:03 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/13 16:39:54 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//DBG
#include "push_swap.h"
#include "psw_inst.h"
#include "psw_monitor.h"

t_inst_swtch	*switchboard(void)
{
	static t_inst_swtch	inst_set[] = {
	[SA] = {.inst = &sa, .call = "sa"},
	[SB] = {.inst = &sb, .call = "sb"},
	[SS] = {.inst = &ss, .call = "ss"},
	[PA] = {.inst = &pa, .call = "pa"},
	[PB] = {.inst = &pb, .call = "pb"},
	[RA] = {.inst = &ra, .call = "ra"},
	[RB] = {.inst = &rb, .call = "rb"},
	[RR] = {.inst = &rr, .call = "rr"},
	[RRA] = {.inst = &rra, .call = "rra"},
	[RRB] = {.inst = &rrb, .call = "rrb"},
	[RRR] = {.inst = &rrr, .call = "rrr"},
	[END] = {.inst = NULL, .call = "END"}
	};

	return (inst_set);
}

t_inst	fetch_inst(t_inst_swtch *inst_set, char *inst_call)
{
	t_inst_id		slot;

	slot = 0;
	while (inst_set[slot].inst != NULL
		&& ft_strncmp(inst_set[slot].call, inst_call, 3))
		slot++;
	return (inst_set[slot].inst);
}

void	log_inst(t_game *game)
{
	size_t		i;
	t_inst_id	substitute;

	i = 0;
	while (i < game->buf->entries)
	{
		substitute = 0;
		if ((INST[i] == SA && INST[i + 1] == SB)
			|| (INST[i] == SB && INST[i + 1] == SA))
			substitute = SS;
		else if ((INST[i] == RA && INST[i + 1] == RB)
			|| (INST[i] == RB && INST[i + 1] == RA))
			substitute = RR;
		else if ((INST[i] == RRA && INST[i + 1] == RRB)
			|| (INST[i] == RRB && INST[i + 1] == RRA))
			substitute = RRR;
		else
			str_to_vctr(game->log, switchboard()[INST[i++]].call);
		if (substitute)
		{
			str_to_vctr(game->log, switchboard()[substitute].call);
			i += 2;
		}
		str_to_vctr(game->log, "\n");
	}
}

void	loop(size_t *counter) // DEBUGGING
{
	static size_t	i;

	i++;
//	dprintf(1, "OH BOY %lu wasted instructions\n", i * 25);
	*counter = 0;
}

void	buf_inst(t_game *game, t_inst_id inst)
{
	static size_t repeated_inst;

	if (inst == END)
		log_inst(game);
	else
	{
		(switchboard()[inst].inst)(game);
		vctr_push(game->buf, &inst);
		if (PRV_MOV == (int)inst)//DBG
			repeated_inst++;
		else
			repeated_inst = 0;
		if (repeated_inst >= 25)
			loop(&repeated_inst);
		PRV_MOV = inst;
		if (MONITORING) // MONITORING
			psw_monitor(game);
	}
/*	if (TIMEOUT_LOOP) //DEBUG
	{
		log_inst(game);
		write(1, game->log->data, game->log->entries);
		exit(1);
	}*/
}
