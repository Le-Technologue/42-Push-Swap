/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:25:56 by wetieven          #+#    #+#             */
/*   Updated: 2021/10/07 17:39:49 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "psw_parsing.h"
#include "psw_inst.h"
#include "psw_algo.h"
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
	if (function >= PSW_GAME)
	{	
		if (cause == CLEAR)
		{
			write(1, game->log->data, game->log->entries);
			psw_end_report(game);
		}
		free(game->set);
		free(game->a.stk);
		free(game->b.stk);
		vctr_exit(game->buf);
		vctr_exit(game->log);
	}
	return (cause);
}

static t_error	psw_game(t_game *game)
{
	game->b.stk = malloc(sizeof(t_val) * GAME_QTY);
	if (!game->b.stk)
		return (MEM_ALLOC);
	if (vctr_init(&game->buf, sizeof(t_inst_id), 512))
		return (MEM_ALLOC);
	if (vctr_init(&game->log, sizeof(char), 2048))
		return (MEM_ALLOC);
	PRV_MOV = END;
	LOAD_A = GAME_QTY;
	LOAD_B = 0;
	psw_solver(game);
	return (CLEAR);
}

int	main(int ac, char **av)
{
	t_error	error;
	t_game	game;

	if (ac == 1)
	{
		ft_putendl_fd("USAGE : ./push_swap [m] INT LIST", 1);
		return (ERROR);
	}
	game.info.qty = ac - 1;
	error = psw_parsing(&game, av);
	if (error)
		return (psw_shutdown(&game, error, PSW_PARSING));
	error = psw_game(&game);
	if (error)
		return (psw_shutdown(&game, error, PSW_GAME));
	return (psw_shutdown(&game, CLEAR, MAIN_END));
}
