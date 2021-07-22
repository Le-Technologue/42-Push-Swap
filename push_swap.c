/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:25:56 by wetieven          #+#    #+#             */
/*   Updated: 2021/07/22 15:03:28 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "push_swap.h"

void	psw_shutdown(t_error cause, t_fid function) // we'll need a t_fid enum to identify our functions in some header
{
}

t_error	game_init(t_game *game, char **av)
{
	size_t	i;

	game->a->stk = malloc(sizeof(val) * game->info.qty);
	if (!game->a->stk)
		return (mem_alloc);
	game->b->stk = malloc(sizeof(val) * game->info.qty);
	if (!game->b->stk)
		return (mem_alloc);
	i = 0;
	while (i < game->info.qty)
	{
		game->a->stk[i] = game->set[i]; 
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
	int		i;
	long	buf;
	char	**ptr;

	i = 0;
	while (i < game->info.qty)
	{
		ptr = av[i + 1][0];
		if (!ft_isdigit(**ptr))
			return (parse);
		buf = ptr_atol_base(ptr, "0123456789");
		if (ptr != '\0' || INT_MIN < buf || buf > INT_MAX)
			return (parse);
		game->set[i].val = buf;
	}
// Then quicksort it, check for doubles, produce according metadata
	return (clear);
}

int main(int ac, char **av)
{
	t_error	error;
	t_game	game;

	game.info.qty = ac - 1;
	game->set = malloc(sizeof(val) * game->info.qty);
	if (!game->set)
		return (psw_shutdown(mem_alloc, main));
	if (arg_parse(&game, av) != clear)
		return (psw_shutdown(parse, arg_parse));
	error = game_init(&game, av);
	if (error)
		return (psw_shutdown(error, game_init));
}
