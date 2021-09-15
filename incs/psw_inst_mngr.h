/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inst_mngr.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 08:10:30 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/15 17:56:58 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_INST_MNGR_H
# define PSW_INST_MNGR_H

# include "push_swap.h"
# include "psw_algo.h"

typedef size_t	(*t_inst_mngr)(t_game *game, t_step step);

size_t	psh(t_game *game, t_step step);
size_t	swp(t_game *game, t_step step);
size_t	rot(t_game *game, t_step step);
size_t	rrot(t_game *game, t_step step);

#endif
