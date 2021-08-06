/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_recording.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 18:34:58 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/06 21:15:39 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Record inst sequence
void	(t_game *game, t_inst_swtch *inst_set, int load)
{
	int	i;

	i = 0;
	while (i < load)
	{
		str_to_vctr(game->cue, inst_set[buf[i]].call);
		str_to_vctr(game->cue, "\n");
		i++;
	}
}

void	unload_buf(t_game *game, t_inst_swtch *inst_set, int load)
{
	//Execute instructions
}

void	inst_buffer(t_game *game, t_inst_swtch *inst_set, t_inst_id inst)
{
	static t_inst_id	buf[2];
	static int			load;

	if (inst == END)
		unload_buf(game, inst_set, load);
	if (load == 2)
	{
		load--;
		if ((buf[0] == SA && buf[1] == SB) || (buf[0] == SB && buf[1] == SA))
			buf[0] = SS;
		else if ((buf[0] == RA && buf[1] == RB)
				|| (buf[0] == RB && buf[1] == RA))
			buf[0] = RR;
		else if ((buf[0] == RRA && buf[1] == RRB)
				|| (buf[0] == RRB && buf[1] == RRA))
			buf[0] = RRR;
		else
		{
			load++;
			unload_buf(game, inst_set, load);
			load = 0;
		}
	}
	buf[load++] = inst;
}
