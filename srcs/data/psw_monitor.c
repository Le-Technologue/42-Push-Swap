/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:10:45 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/15 16:45:06 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "psw_inst.h"
#include "psw_probes.h"

static void	psw_erect_stks(t_game *game, size_t a, size_t b, int wid)
{
	int			i;

	ft_printf("v %lu - %s v\n", game->buf->entries, switchboard()[PRV_MOV].call);
	while (a > b)
	{
		ft_printf("%*lu - ", wid + 1, a);
		ft_printf("%*i | \n", wid, game->a.stk[--a].val);
	}
	while (b > a)
	{
		ft_printf("%*lu - ", wid + 1, b);
		i = 0;
		while (i++ < wid)
			ft_printf(" ");
		ft_printf(" | %*i\n", wid, game->b.stk[--b].val);
	}
	while (a || b)
	{
		ft_printf("%*lu - ", wid + 1, a);
		ft_printf("%*i | %*i\
			\n", wid, game->a.stk[--a].val, wid, game->b.stk[--b].val);
	}
}

void	psw_monitor(t_game *game)
{
	static int	width;
	int			i;

	if (!width)
	{
		width = (int)ft_digit_count(game->set[GAME_QTY - 1]->val, 10);
		if ((int)ft_digit_count(game->set[0]->val, 10) > width)
			width = (int)ft_digit_count(game->set[0]->val, 10);
	}
	psw_erect_stks(game, game->a.load, game->b.load, width);
	i = 0;
	while (i++ <= width)
		ft_printf(" ");
	ft_printf(" - A");
	i = 1;
	while (i++ < width)
		ft_printf("_");
	ft_printf("_|_");
	i = 1;
	while (i++ < width)
		ft_printf("_");
	ft_printf("B\n");
	ft_printf("^ %lu - %s ^\n\
			\n", game->buf->entries, switchboard()[PRV_MOV].call);
}

void	psw_end_report(t_game *game)
{
	if (MONITORING)
	{
		ft_printf("^ SOLUTION ^\n\n");
		psw_monitor(game);
		if (sorted(game, A, 0) && !LOAD_B)
			ft_printf("STACK SORTED :D\n");
		else
			ft_printf("STACK UNSORTED ^^\"\n");
		ft_printf("%lu raw instructions\n", game->buf->entries);
		ft_printf("%li joint instructions\
				\n", game->buf->entries - ft_word_count(game->log->data, '\n'));
		ft_printf("%i remaining instructions\
				\n", ft_word_count(game->log->data, '\n'));
	}
}
