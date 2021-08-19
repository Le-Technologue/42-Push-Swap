/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:25:56 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/19 15:11:57 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"
#include "psw_parsing.h"
#include "psw_algo.h"

t_error	psw_shutdown(t_game *game, t_error cause, t_fid function)
{
	if (cause == MEM_ALLOC)
		ft_putendl_fd("Memory is lacking, please close Google Chrome", 1);
	if (function == PSW_PARSING)
		if (cause == PARSE)
			ft_putendl_fd("Arguments should belong to the int set and exclude duplicates", 1);
	if (function >= PSW_GAME)
	{	
		write(1, game->log->data, game->log->entries);
		if (game->b.stk)
			free(game->b.stk);
		if (game->log)
			vctr_exit(game->log);
		if (PVT)
			vctr_exit(PVT);
	}
	if (game->a.stk)
		free(game->a.stk);
	if (game->set)
		free(game->set);
	return (CLEAR);
}

t_error	psw_game(t_game *game)
{
	game->b.stk = malloc(sizeof(t_val) * game->qty);
	if (!game->b.stk)
		return (MEM_ALLOC);
	if (vctr_init(&game->log, sizeof(char), 512))
		return (MEM_ALLOC);
	if (vctr_init(&PVT, sizeof(size_t), 32))
		return (MEM_ALLOC);
	game->a.load = game->qty;
	game->b.load = 0;
	psw_solver(game);
	return (CLEAR);
}
/*	while (game->qty)
	i = game->qty; // we had to start by the end when we pushed values, but it could be done otherwise
	game->a->top = NULL; //mhh but how to initialise stack b as well?
	dll_push(game->a->top, new_dln(game->val[i].val));
	bottom = top;
	while (--i >= 0)
	dll_push(game->a->top, new_dln(game->val[i].val));
*/

t_error	psw_parsing(t_game *game, char **av)
{
	size_t	i;
	long	buf;
	char	*ptr;
	t_error	outcome;

	i = 0;
	game->info.mon = 1; // MONITOR
	while (i < game->qty)
	{
		ptr = av[i + 1];
		if (!ft_isdigit(*ptr))
			return (PARSE);
		buf = ptr_atol_base(&ptr, "0123456789");
		if (*ptr != '\0' || INT_MIN > buf || buf > INT_MAX)
			return (PARSE);
		game->a.stk[game->qty - 1 - i++].val = buf;
	}
	outcome = game_setup(game);
	return (outcome);
}

int main(int ac, char **av)
{
	t_error	error;
	t_game	game;

	if (ac == 1)
	{
		ft_putendl_fd("USAGE : ./push_swap [INT LIST]", 1);
		return (ERROR);
	}
	game.qty = ac - 1;
	game.a.stk = malloc(sizeof(t_val) * game.qty);
	if (!game.a.stk)
		return (psw_shutdown(&game, MEM_ALLOC, MAIN_START));
	error = psw_parsing(&game, av);
	if (error)
		return (psw_shutdown(&game, error, PSW_PARSING));
	error = psw_game(&game);
	if (error)
		return (psw_shutdown(&game, error, PSW_GAME));
	return (psw_shutdown(&game, CLEAR, MAIN_END));
}
