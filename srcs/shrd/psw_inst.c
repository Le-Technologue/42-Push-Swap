/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:43:03 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/04 21:44:59 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// swap top of stack a
void	sa(t_game *game)
{
	if (game->a.top > 0)
		ft_swap(game->a.stk[game->a.top], game->a.stk[game->a.top - 1]);
}

// swap top of stack b
void	sb(t_game *game)
{
	if (game->b.top > 0)
		ft_swap(game->b.stk[game->b.top], game->b.stk[game->b.top - 1]);
}

// swap both stacks tops
void	ss(t_game *game)
{
	sa(game);
	sb(game);
}

// push top of b to a
void	pa(t_game *game)
{
}

pb // push a summit on top of b

// queue top of a - shift values up the stack
void	ra(t_game *game)
{
	t_val	*buf;
	size_t	i;

	i = 0;
	while (i <= game->a.top)
	{

		buf = game->a.stk[i + 1];
		game->a.stk[i + 1] = game->a.stk[i];
		i++;
	}
	game->a.stk[0] = buf;
}


rb
rr
rra // push bottom of a - shift values down the stack
rrb
rrr
