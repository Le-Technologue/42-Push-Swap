/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:45:42 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/17 12:37:38 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"

// push top of b to a
void	pa(t_game *game)
{
	if (!game->b.load)
		return ;
	game->a.load++;
	game->a.stk[game->a.load - 1] = game->b.stk[game->b.load - 1];
	game->b.load--;
}

// push a summit on top of b
void	pb(t_game *game)
{
	if (!game->a.load)
		return ;
	game->b.load++;
	game->b.stk[game->b.load - 1] = game->a.stk[game->a.load - 1];
	game->a.load--;
}
