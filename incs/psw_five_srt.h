/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_five_srt.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:58:41 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/01 10:11:43 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_FIVE_SRT_H
# define PSW_FIVE_SRT_H

# include "push_swap.h"

size_t	srt_top_A(t_game *game);
size_t	srt_top_B(t_game *game);
size_t	srt_tops(t_game *game);
void	three_srt(t_game *game);
void	five_srt_B(t_game *game);
void	five_srt_A(t_game *game);

#endif
