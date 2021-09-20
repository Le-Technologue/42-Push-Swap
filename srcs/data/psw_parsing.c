/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:18:55 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/20 09:23:05 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"
#include "push_swap.h"
#include "psw_chk_dupl.h"

static t_error	psw_monitoring_toggle(t_game *game, char **first_arg, long *buf)
{
	if (**first_arg == 'm')
	{
		if (game->info.qty <= 1)
			return (PARSE);
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

// Thank the norm for that signed counter. A long should be enough
// knowing we're not dealing with anything other than ints though.
static t_error	game_setup(t_game *game, long *buf)
{
	t_error	error;

	error = CLEAR;
	if (MONITORING)
		GAME_QTY--;
	error = psw_chk_dupl(game, buf);
	free(buf);
	if (error != PARSE)
		return (error);
	free(game->a.stk);
	free(game->set);
	return (error);
}

t_error	psw_parsing(t_game *game, char **av)
{
	size_t	i;
	long	*buf;
	char	*ptr;

	buf = malloc(sizeof(t_val) * game->info.qty);
	if (!buf)
		return (MEM_ALLOC);
	i = 0;
	if (psw_monitoring_toggle(game, &av[1], buf) == CLEAR)
	{
		while (++i < GAME_QTY)
		{
			ptr = av[i + 1];
			if (!ft_isdigit(*ptr))
				break ;
			buf[GAME_QTY - 1 - i] = ptr_atol_base(&ptr, "0123456789");
			if (*ptr != '\0' || buf[GAME_QTY - 1 - i] < INT_MIN
				|| buf[GAME_QTY - 1 - i] > INT_MAX)
				break ;
		}
	}
	if (i == GAME_QTY)
		return (game_setup(game, buf));
	free(buf);
	return (PARSE);
}
