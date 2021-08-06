/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:43:03 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/06 09:43:10 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "psw_inst.h"

t_inst	switchboard(char *inst_call)
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
	[NaI] = {.inst = NULL}
	};
	t_inst_id		slot;

	slot = 0;
	while(inst_set[slot].inst != NULL
			&& ft_strncmp(inst_set[slot].call, inst_call, 3))
		slot++;
	return (inst_set[slot].inst);
}
