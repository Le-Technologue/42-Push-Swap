/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:45:42 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/07 13:59:05 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push top of b to a
void	pa(t_game *game)
{
	game->a.top++;
	game->a.stk[game->a.top] = game->b.stk[game->b.top];
	game->b.top--;
}

// push a summit on top of b
void	pb(t_game *game)
{
	game->b.top++;
	game->b.stk[game->b.top] = game->a.stk[game->a.top];
	game->a.top--;
}
