/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:43:03 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/07 13:57:03 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "psw_inst.h"

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
	[END] = {.inst = NULL}
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

void	join_inst(t_game *game, t_inst_id *buf, int *load, t_inst_id substitute)
{
	while (--(*load) >= 0)
	{
		if (buf[*load] == SA)
			sa(game);
		else if (buf[*load] == SB)
			sb(game);
		else if (buf[*load] == PA)
			pb(game);
		else if (buf[*load] == PB)
			pa(game);
		else if (buf[*load] == RA)
			rra(game);
		else if (buf[*load] == RB)
			rrb(game);
		else if (buf[*load] == RRA)
			ra(game);
		else if (buf[*load] == RRB)
			rb(game);
	}
	(switchboard()[substitute].inst)(game);
	buf[0] = substitute;
	*load = 1;
}

//Commit latest instructions in cue sheet
void	unload_buf(t_game *game, t_inst_swtch *inst_set,
				t_inst_id *buf, int *load)
{
	int	i;

	i = 0;
	while (i < *load)
	{
		str_to_vctr(game->cue, inst_set[buf[i]].call);
		str_to_vctr(game->cue, "\n");
		i++;
	}
	*load = 0;
}

void	buf_inst(t_game *game, t_inst_id inst)
{
	static t_inst_id	buf[2];
	static int			load;
	t_inst_id			substitute;

	if (load == 2 || inst == END)
	{
		substitute = 0;
		if ((buf[0] == SA && buf[1] == SB) || (buf[0] == SB && buf[1] == SA))
			substitute = SS;
		else if ((buf[0] == RA && buf[1] == RB)
			|| (buf[0] == RB && buf[1] == RA))
			substitute = RR;
		else if ((buf[0] == RRA && buf[1] == RRB)
			|| (buf[0] == RRB && buf[1] == RRA))
			substitute = RRR;
		else
			unload_buf(game, switchboard(), buf, &load);
		if (substitute)
			join_inst(game, buf, &load, substitute);
	}
	(switchboard()[inst].inst)(game);
	buf[load++] = inst;
}
