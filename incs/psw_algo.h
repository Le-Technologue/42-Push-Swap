/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:13:57 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/09 16:28:46 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "push_swap.h"

// Calculations
# define MED (low + (high - low) / 2)
# define L_HLFMED (low + (MED - low) / 2)
# define H_HLFMED (MED + 1 + (high - (MED + 1)) / 2)
# define SET_QTY (high - low + 1)
# define RMNG (high - low - pushes + 1)
# define TO_SORT_OVER_MED (high - MED)
# define TO_SORT_UNDR_MED (MED - low)

// Placeholders
# define PVT ((size_t *)(game->info.pvt->data))
# define LST_PVT (game->info.pvt->entries)

// Conditions
//# define QCKSRT_THRESHOLD (high - low < 50)
# define LASTSRT_THRESHOLD (high - low <= 63)
# define TWIN_INSSRT_THRSHLD (high - low <= 30)
# define INSSRT_THRESHOLD (high - low <= 15)
//# define UNSORTED_STKS !chk_A(game) && !chk_B(game)

typedef enum e_mode {
	A_SPLT,
	A_SEC,
	A_STOR,
	A_INS,
	A,
	B_SPLT,
	B_SEC,
	B_STOR,
	B_INS,
	B,
	LAST
}	t_mode;

t_stk	*stk_ptr(t_game *game, t_mode step);
void	qcksrt_b(t_game *game, size_t high, size_t low, t_mode step);
void	qcksrt_a(t_game *game, size_t low, size_t high, t_mode step);
void	psw_solver(t_game *game);

#endif
