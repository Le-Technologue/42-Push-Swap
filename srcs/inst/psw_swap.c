/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:46:30 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/16 20:27:45 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "psw_inst.h"

static void	psw_swap(t_val *a, t_val *b)
{
	t_val	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// swap top of stack a
void	sa(t_game *game)
{
	if (game->a.load >= 2)
		psw_swap(&game->a.stk[TOP_A], &game->a.stk[TOP_A - 1]);
}

// swap top of stack b
void	sb(t_game *game)
{
	if (game->b.load >= 2)
		psw_swap(&game->b.stk[TOP_B], &game->b.stk[TOP_B - 1]);
}

// swap both stacks tops
void	ss(t_game *game)
{
	sa(game);
	sb(game);
}
