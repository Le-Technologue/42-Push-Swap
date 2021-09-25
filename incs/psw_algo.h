/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:13:57 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/25 09:59:19 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_ALGO_H
# define PSW_ALGO_H

# include "push_swap.h"

// Conditions
# define LASTSRT_THRESHOLD (high - low <= 63)
# define TWIN_INSSRT_THRSHLD (high - low <= 31)
# define INSSRT_THRESHOLD (high - low <= 15)

// Calculations
# define MED (low + (high - low) / 2)
# define L_HLFMED (low + (MED - low) / 2)
# define RMNG (high - low - pushes)

//# define SET_QTY (high - low + 1)
//# define H_HLFMED (MED + (high - MED) / 2)

// Sorting mode enum allowing adaptative functions
// for each step of the sorting algorithm
typedef enum e_step {
	A_SPLT,
	A_SEC,
	A_INS,
	A,
	B_SPLT,
	B_SEC,
	B_INS,
	B,
	LAST
}	t_step;

void	psw_solver(t_game *game);

#endif
