/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:49:27 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/23 01:15:26 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "psw_parsing.h"
#include "psw_inst.h"
#include "psw_probes.h"
#include "psw_monitor.h"

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
		if (cause != MEM_ALLOC)
		{
			free(game->a.stk);
			free(game->b.stk);
		}
	}
	vctr_exit(game->buf);
	vctr_exit(game->log);
	return (cause);
}

t_error	psw_checker(t_game *game)
{
	char		*call;
	t_inst_id	inst;

	game->b.stk = malloc(sizeof(t_val) * GAME_QTY);
	if (!game->b.stk)
		return (psw_shutdown(game, MEM_ALLOC, CHECKER));
	PRV_MOV = END;
	LOAD_A = GAME_QTY;
	LOAD_B = 0;
	if (MONITORING)
		psw_monitor(game);
	while (stdin_gnl(&call) > 0)
	{
		inst = fetch_inst_id(switchboard(), call);
		free(call);
		if (inst == END)
			return (PARSE);
		buf_inst(game, inst);
	}
	free(call);
	buf_inst(game, END);
	return (CLEAR);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_error	error;

	if (ac <= 1)
		return (PARSE);
	game.info.qty = ac - 1;
	if (vctr_init(&game.buf, sizeof(t_inst_id), 512))
		return (MEM_ALLOC);
	if (vctr_init(&game.log, sizeof(char), 2048))
	{
		vctr_exit(game.buf);
		return (MEM_ALLOC);
	}
	error = psw_parsing(&game, av);
	if (error)
		return (psw_shutdown(&game, error, PSW_PARSING));
	if (psw_checker(&game) == PARSE)
		return (psw_shutdown(&game, PARSE, MAIN_END));
	if (!game.b.load && sorted(&game, A, 0))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (psw_shutdown(&game, CLEAR, MAIN_END));
}
