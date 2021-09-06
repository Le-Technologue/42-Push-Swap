/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_probes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:23:14 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/03 14:32:11 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROBES_H
# define PROBES_H

#include "push_swap.h"
#include "psw_algo.h"

t_stk	*stk_ptr(t_game *game, t_mode step);
size_t	psw_srch_key(t_stk *ptr, size_t load, size_t sought);
t_stk	*psw_key_locat(t_game *game, size_t sought);
_Bool	sorted(t_game *game, t_mode stack, size_t low);

#endif
