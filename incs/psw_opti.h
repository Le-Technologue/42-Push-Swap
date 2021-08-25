/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_opti.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:48:34 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/24 13:35:54 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_OPTI_H
# define PSW_OPTI_H

# include "psw_algo.h"

size_t	psh(t_game *game, t_mode mode);
size_t	swp(t_game *game, t_mode mode);
size_t	rot(t_game *game, t_mode mode);
size_t	rrot(t_game *game, t_mode mode);

#endif