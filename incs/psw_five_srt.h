/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_five_srt.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:58:41 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/14 10:31:26 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_FIVE_SRT_H
# define PSW_FIVE_SRT_H

# include "push_swap.h"

size_t	srt_top_a(t_game *game);
size_t	srt_top_b(t_game *game);
size_t	srt_tops(t_game *game);
void	three_srt(t_game *game, size_t low, size_t high);
void	five_srt_b(t_game *game, size_t high, size_t low);
void	five_srt_a(t_game *game, size_t low, size_t high);

#endif
