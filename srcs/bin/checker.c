/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:49:27 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/16 11:27:41 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "psw_parsing.h"
#include "psw_inst.h"
#include "psw_probes.h"

static t_error	psw_shutdown(t_game *game, t_error cause, t_fid function)
{
	if (cause != CLEAR)
		ft_putendl_fd("Error", 2);
	if (cause == MEM_ALLOC)
		ft_putendl_fd("Memory is lacking, please close Google Chrome", 1);
	if (function == PSW_PARSING)
		if (cause == PARSE)
			ft_putendl_fd("Arguments have to belong to the int set\
 and exclude duplicates.", 1);
	if (function >= CHECKER)
	{
		free(game->set);
		free(game->a.stk);
		free(game->b.stk);
	}
	return (cause);
}

t_error	psw_checker(t_game *game)
{
	char	*call;
	t_inst	inst;

	game->b.stk = malloc(sizeof(t_val) * GAME_QTY);
	if (!game->b.stk)
		return (psw_shutdown(game, MEM_ALLOC, CHECKER));
	while (get_next_line(0, &call))
	{
		inst = fetch_inst(switchboard(), call);
		if (inst == NULL)
			return (PARSE);
		(inst)(game);
	}
	return (CLEAR);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_error	error;

	if (ac == 1)
		return (PARSE);
	game.info.qty = ac - 1;
	error = psw_parsing(&game, av);
	if (error)
		return (psw_shutdown(&game, error, PSW_PARSING));
	psw_checker(&game);
	if (!game.b.load && sorted(&game, A, 0))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (psw_shutdown(&game, CLEAR, MAIN_END));
}
