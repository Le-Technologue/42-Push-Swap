/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:30:08 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/07 14:04:46 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// queue top of stack - shift remaining values up the stack
static void	rot_stk_top_botm(t_val *stk, size_t top)
{
	t_val	upper;

	upper = stk[top];
	while (top > 0)
	{
		stk[top] = stk[top - 1];
		top--;
	}
	stk[0] = upper;
}

void	ra(t_game *game)
{
	rot_stk_top_botm(game->a.stk, game->a.top);
}

void	rb(t_game *game)
{
	rot_stk_top_botm(game->b.stk, game->b.top);
}

void	rr(t_game *game)
{
	ra(game);
	rb(game);
}
