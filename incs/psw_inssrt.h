/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inssrt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:59:01 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/10 10:12:59 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_INSSRT_H
# define PSW_INSSRT_H

# include "psw_algo.h"

void	psw_ftch_key(t_game *game, t_mode step, size_t sought, size_t nxt);
void	inssrt_b(t_game *game, size_t high, size_t low);
void	inssrt_a(t_game *game, size_t low, size_t high);
void	twin_inssrt(t_game *game, size_t low, size_t high);

#endif
