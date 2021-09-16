/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:43:03 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/16 19:54:12 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	[END] = {.inst = NULL, .call = NULL}
	};

	return (inst_set);
}

t_inst_id	fetch_inst_id(t_inst_swtch *inst_set, char *inst_call)
{
	t_inst_id		slot;

	slot = 0;
	while (inst_set[slot].inst != NULL
		&& ft_strncmp(inst_set[slot].call, inst_call, 4))
		slot++;
	return (slot);
}

static t_inst_id	inst_coupling(t_game *game, size_t i)
{
	if (game->buf->entries >= 2)
	{
		if ((INST[i] == SA && INST[i + 1] == SB)
			|| (INST[i] == SB && INST[i + 1] == SA))
			return (SS);
		else if ((INST[i] == RA && INST[i + 1] == RB)
			|| (INST[i] == RB && INST[i + 1] == RA))
			return (RR);
		else if ((INST[i] == RRA && INST[i + 1] == RRB)
			|| (INST[i] == RRB && INST[i + 1] == RRA))
			return (RRR);
	}
	return (0);
}

void	log_inst(t_game *game)
{
	size_t		i;
	t_inst_id	substitute;

	i = 0;
	while (i < game->buf->entries)
	{
		substitute = inst_coupling(game, i);
		if (substitute)
		{
			str_to_vctr(game->log, switchboard()[substitute].call);
			i += 2;
		}
		else
			str_to_vctr(game->log, switchboard()[INST[i++]].call);
		str_to_vctr(game->log, "\n");
	}
}

void	buf_inst(t_game *game, t_inst_id inst)
{
	if (inst == END)
		log_inst(game);
	else
	{
		(switchboard()[inst].inst)(game);
		vctr_push(game->buf, &inst);
		PRV_MOV = inst;
		if (MONITORING)
			psw_monitor(game);
	}
}
