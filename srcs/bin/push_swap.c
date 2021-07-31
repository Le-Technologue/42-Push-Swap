/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:25:56 by wetieven          #+#    #+#             */
/*   Updated: 2021/07/31 10:59:46 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "push_swap.h"
#include "data.h"

t_error	psw_shutdown(t_game *game, t_error cause, t_fid function)
{
	if (cause == mem_alloc)
		ft_putendl_fd("Memory is lacking, please close Google Chrome", 1);
	if (function == ARG_PARSE)
	{
		ft_putendl_fd("Arguments should belong to the int set and exclude any duplicates", 1);
		free(game->set);
		free(game->a.stk);
		free(game->b.stk);
	}
	return (clear);
}

t_error	game_init(t_game *game)
{
	size_t	i;

	game->a.stk = malloc(sizeof(t_val *) * game->info.qty);
	if (!game->a.stk)
		return (mem_alloc);
	game->b.stk = malloc(sizeof(t_val *) * game->info.qty);
	if (!game->b.stk)
		return (mem_alloc);
	i = 0;
	while (i < game->info.qty)
	{
		game->a.stk[i] = &game->set[i];
		i++;
	}
	game->a.top = game->info.qty;
	game->b.top = 0;
	return (clear);
}
/*	while (game->info.qty)
	i = game->info.qty; // we had to start by the end when we pushed values, but it could be done otherwise
	game->a->top = NULL; //mhh but how to initialise stack b as well?
	dll_push(game->a->top, new_dln(game->val[i].val));
	bottom = top;
	while (--i >= 0)
	dll_push(game->a->top, new_dln(game->val[i].val));
*/

t_error	arg_parse(t_game *game, char **av)
{
	size_t	i;
	long	buf;
	char	*ptr;
	t_val	**wrk_set;

	i = 0;
	while (i < game->info.qty)
	{
		ptr = av[i + 1];
		if (!ft_isdigit(*ptr))
			return (parse);
		buf = ptr_atol_base(&ptr, "0123456789");
		if (*ptr != '\0' || INT_MIN < buf || buf > INT_MAX)
			return (parse);
		game->set[i].val = buf;
		i++;
	}
	wrk_set = malloc(sizeof(t_val **) * game->info.qty);
	if (!*wrk_set)
		return (mem_alloc);
	i = 0;
	while (i < game->info.qty)
		wrk_set[i] = &game->set[i];
// Then sort it, check for doubles, give indexes, produce according metadata, free the wrkset
	return (clear);
}

int main(int ac, char **av)
{
	t_error	error;
	t_game	game;

	if (ac == 1)
		ft_putendl_fd("USAGE : ./push_swap [INT LIST]", 1);
	game.info.qty = ac - 1;
	game.set = malloc(sizeof(t_val) * game.info.qty);
	if (!game.set)
		return (psw_shutdown(&game, mem_alloc, MAIN));
	if (arg_parse(&game, av) != clear)
		return (psw_shutdown(&game, parse, ARG_PARSE));
	error = game_init(&game);
	if (error)
		return (psw_shutdown(&game, error, GAME_INIT));
}
