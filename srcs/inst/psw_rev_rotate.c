/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:34:12 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/09 14:25:47 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"

// push bottom up the top of the stack - shift remaining values down the stack
static void	rot_stk_botm_up(t_val *stk, size_t top)
{
	t_val	botm;
	size_t	i;

	botm = stk[0];
	i = 0;
	while (i < top)
	{
		stk[i] = stk[i + 1];
		i++;
	}
	stk[top] = botm;
}

void	rra(t_game *game)
{
	rot_stk_botm_up(game->a.stk, game->a.top);
}

void	rrb(t_game *game)
{
	rot_stk_botm_up(game->b.stk, game->b.top);
}

void	rrr(t_game *game)
{
	rra(game);
	rrb(game);
}
