/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_algo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:13:57 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/17 11:14:18 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_ALGO_H
# define PSW_ALGO_H

# include "push_swap.h"

// Conditions
# define LASTSRT_THRESHOLD 63
# define TWIN_INSSRT_THRSHLD 31
# define INSSRT_THRESHOLD 15

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
