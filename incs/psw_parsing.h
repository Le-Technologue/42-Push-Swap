/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:21:57 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/04 16:22:06 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_error	game_setup(t_game *game);
t_error	psw_mrgsort(t_val **set, const size_t start, const size_t end);
t_error	psw_chkdupl(t_val **set, size_t size);
t_error	assign_keys(t_val **set, size_t range);

#endif
