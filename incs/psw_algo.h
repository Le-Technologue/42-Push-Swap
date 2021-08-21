/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:21:52 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/21 18:57:14 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# define PVT ((size_t *)(game->info->pvt->data))
# define LST_PVT (game->info->pvt->entries)

typedef enum e_mode {
	A_3,
	A_INS,
	A,
	B_3,
	B_INS,
	B
	START,
}	t_mode;

void	psw_solver(t_game *game);

#endif
