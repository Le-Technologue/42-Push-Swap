/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:25:56 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/23 18:13:33 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "limits.h"
#include "libft.h"

void	psw_shutdown(t_error cause, t_fid function) // we'll need a t_fid enum to identify our functions in some header
{
}

t_error	arg_check(t_game *game, char **av)
{
	int		i;
	long	buf;

	i = game->info.qty;

	while (--i >= 0)
	{
		buf = ft_atol_base(av[i + 1], "0123456789");
		if (INT_MIN < buf || buf > INT_MAX)
			return (parse);
		game->nbrs[i].val = buf;
		if (game->nbrs[i].val == 0)
		{
			if (!ft_isnumber(av[i]))
				return (parse);
		}
	}
	return (clear);
}

//t_error	game_init(

t_error	arg_parse(t_game *game, char **av) //unsure about that function name or functional segments
{
	i = game->info.qty - 1;

	game->a->top = NULL; //mhh but how to initialise stack b as well?
	dll_push(game->a->top, new_dln(game->val[i].val));
	bottom = top;
	while (--i >= 0)
		dll_push(game->a->top, new_dln(game->val[i].val));
	// Then quicksort and check for doubles
	return (clear);
}

int main(int ac, char **av)
{
	t_error	error;
	t_game	game;

	game.info.qty = ac - 1;
	if (arg_check(&game, av) != clear)
		return (psw_shutdown(parse, arg_check));
	error = arg_parse(&game, av);
	if (error)
		return (psw_shutdown(error, arg_parse));
}
