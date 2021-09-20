/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_mrgsrt.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:16:28 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/10 10:36:59 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_MRGSRT_H
# define PSW_MRGSRT_H

# include "psw_algo.h"

void	mrg_to_b(t_game *game, size_t low, size_t high, size_t to_sort);
void	mrg_to_a(t_game *game, size_t high, size_t low, size_t to_sort);

#endif
