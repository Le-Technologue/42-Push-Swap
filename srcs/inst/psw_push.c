/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:45:42 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/14 16:01:09 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"

// push top of b to a
void	pa(t_game *game)
{
	game->a.load++;
	game->a.stk[TOP_A] = game->b.stk[TOP_B];
	game->b.load--;
}

// push a summit on top of b
void	pb(t_game *game)
{
	game->b.load++;
	game->b.stk[TOP_B] = game->a.stk[TOP_A];
	game->a.load--;
}
