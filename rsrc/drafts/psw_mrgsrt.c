/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_mrgsrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:15:41 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/10 10:53:17 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst_mngr.h"
#include "psw_probes.h"
#include "psw_mrgsrt.h"

void	mrg_to_b(t_game *game, size_t low, size_t high, size_t to_sort)
{
	while (UNDR_B || to_sort)
	{
		while (to_sort && (STK_A[TOP_A].key > high || STK_A[TOP_A].key < low))
			(steer_rot(&game->a, low, high))(game, A);
		if (STK_A[TOP_A].key < STK_B[0].key || !UNDR_B)
		{
			psh(game, B);
			to_sort--;
		}
		else if (UNDR_B)
			rrot(game, B_STOR);
		//edge_srt/top_srt_A
	}
}

void	mrg_to_a(t_game *game, size_t high, size_t low, size_t to_sort)
{
	while (UNDR_A || to_sort)
	{
		while (to_sort //UNDR_A + i <= H_HLFMED - MED + 1
				&& (STK_B[TOP_B].key > high || STK_B[TOP_B].key < low))
			(steer_rot(&game->b, low, high))(game, B);
		if (STK_B[TOP_B].key > STK_A[0].key || !UNDR_A) //ouch
		{
			psh(game, A);
			to_sort--;
		}
		else if (UNDR_A) //ouch
			rrot(game, A_STOR);
		//edge_srt/top_srt_A
	}
}
