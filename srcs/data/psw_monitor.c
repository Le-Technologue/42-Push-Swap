/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:10:45 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/14 09:10:12 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //TENTION
#include "push_swap.h"
#include "psw_inst.h"

void	psw_monitor(t_game *game)
{
	size_t		a;
	size_t		b;
	static int	width;
	static int	line_width;
	int			i;

	if (!width)
	{
		width = (int)ft_digit_count(game->set[GAME_QTY - 1]->val, 10);
		if ((int)ft_digit_count(game->set[0]->val, 10) > width)
			width = (int)ft_digit_count(game->set[0]->val, 10);
	}
	if (!line_width)
		line_width = (int)ft_digit_count(LOAD_A, 10);
	a = game->a.load;
	b = game->b.load;
	dprintf(1, "v %lu - %s v\n", game->buf->entries, switchboard()[PRV_MOV].call);
	while (a > b)
	{
		dprintf(1, "%*lu - ", line_width, a);
		dprintf(1, "%*i | \n", width, game->a.stk[--a].val);
	}
	while (b > a)
	{
		dprintf(1, "%*lu - ", line_width, b);
		i = 0;
		while (i++ < width)
			dprintf(1, " ");
		dprintf(1, " | %*i\n", width, game->b.stk[--b].val);
	}
	while (a || b)
	{
		dprintf(1, "%*lu - ", line_width, a);
		dprintf(1, "%*i | %*i\n", width, game->a.stk[--a].val, width, game->b.stk[--b].val);
	}
	i = 0;
	while (i++ < line_width)
		dprintf(1, " ");
	dprintf(1, " - ");
	dprintf(1, "A");
	i = 1;
	while (i++ < width)
		dprintf(1, "_");
	dprintf(1, "_|_");
	i = 1;
	while (i++ < width)
		dprintf(1, "_");
	dprintf(1, "B\n");
	dprintf(1, "^ %lu - %s ^\n\n", game->buf->entries, switchboard()[PRV_MOV].call);
}
