/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:30:08 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/05 14:37:47 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// queue top of stack - shift remaining values up the stack
static void	rot_stk_top_botm(t_val *stk, size_t top)
{
	t_val	top;

	top = stk[top];
	while (top > 0)
	{
		stk[top] = stk[top - 1];
		top--;
	}
	stk[0] = top;
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
