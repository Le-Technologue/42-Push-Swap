/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:21:52 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/24 14:00:06 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "push_swap.h"

# define MED (low + (high - low) / 2)
// # define TO_SORT ((high - low) / 2 + 1)
# define PVT ((size_t *)(game->info.pvt->data))
# define LST_PVT (game->info.pvt->entries)
# define QCKSRT_THRESHOLD (high - low < 50)
# define INSSRT_THRESHOLD (high - low < 25)
//# define UNSORTED_STKS !chk_A(game) && !chk_B(game)

typedef enum e_mode {
	A_3,
	A_INS,
	A,
	B_3,
	B_INS,
	B,
	START
}	t_mode;

size_t	srt_tops(t_game *game, t_mode step, size_t med);
size_t	srt_bottoms(t_game *game, size_t med);
size_t	srt_next_to_top(t_game *game, size_t med);
void	edge_srt(t_game *game, t_mode mode, size_t med);
void	psw_solver(t_game *game);

#endif
