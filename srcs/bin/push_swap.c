/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:25:56 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/15 17:36:03 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "push_swap.h"
#include "psw_parsing.h"
#include "psw_inst.h"
#include "psw_algo.h"
#include "psw_monitor.h"

t_error	psw_shutdown(t_game *game, t_error cause, t_fid function)
{
	if (cause == MEM_ALLOC)
		ft_putendl_fd("Memory is lacking, please close Google Chrome", 1);
	if (function == PSW_PARSING)
		if (cause == PARSE)
			ft_putendl_fd("Error : Arguments have to belong to the int set\
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
	return (CLEAR);
}

t_error	psw_game(t_game *game)
{
	game->b.stk = malloc(sizeof(t_val) * GAME_QTY);
	if (!game->b.stk)
		return (MEM_ALLOC);
	if (vctr_init(&game->buf, sizeof(t_inst_id), 512))
		return (MEM_ALLOC);
	if (vctr_init(&game->log, sizeof(char), 2048))
		return (MEM_ALLOC);
	PRV_MOV = START;
	LOAD_A = GAME_QTY;
	LOAD_B = 0;
	psw_solver(game);
	return (CLEAR);
}

t_error	psw_monitoring_toggle(t_game *game, char **first_arg, long *buf)
{
	if (**first_arg == 'm')
	{
		game->info.mon = 1;
		return (CLEAR);
	}
	else
	{
		game->info.mon = 0;
		buf[GAME_QTY - 1] = ptr_atol_base(first_arg, "0123456789");
		if (buf[GAME_QTY - 1] < INT_MIN || buf[GAME_QTY - 1] > INT_MAX
			|| **first_arg != '\0')
			return (PARSE);
		return (CLEAR);
	}
}

t_error	psw_parsing(t_game *game, char **av)
{
	size_t	i;
	long	*buf;
	char	*ptr;
	t_error	outcome;

	buf = malloc(sizeof(t_val) * game->info.qty);
	if (!buf)
		return (MEM_ALLOC);
	if (psw_monitoring_toggle(game, &av[1], buf) != CLEAR)
		return (PARSE);
	i = 0;
	while (++i < GAME_QTY)
	{
		ptr = av[i + 1];
		if (!ft_isdigit(*ptr))
			return (PARSE);
		buf[GAME_QTY - 1 - i] = ptr_atol_base(&ptr, "0123456789");
		if (INT_MIN > buf[GAME_QTY - 1 - i] || buf[GAME_QTY - 1 - i] > INT_MAX
			|| *ptr != '\0')
			return (PARSE);
	}
	outcome = game_setup(game, buf);
	free(buf);
	return (outcome);
}

int	main(int ac, char **av)
{
	t_error	error;
	t_game	game;

	if (ac == 1)
	{
		ft_putendl_fd("USAGE : ./push_swap [INT LIST]", 1);
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
