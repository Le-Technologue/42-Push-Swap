/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_opti.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:48:34 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/14 14:59:53 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_OPTI_H
# define PSW_OPTI_H

# include "push_swap.h"
# include "psw_algo.h"

size_t	med_srt_tops(t_game *game, t_mode step, size_t med);
size_t	srt_bottoms(t_game *game, size_t med);
size_t	srt_next_to_top(t_game *game, size_t med);
void	edge_srt(t_game *game, t_mode mode, size_t med);

#endif
