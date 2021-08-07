/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:03:54 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/07 11:43:52 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	psw_qcksrt(t_game *game, t_inst_swtch *inst_set)
{
	if (game->a.stk[top] < med)
		buf_inst(game, PB);
	else
		buf_inst(game, RA);
}
