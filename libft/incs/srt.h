/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:36:35 by wetieven          #+#    #+#             */
/*   Updated: 2021/07/27 10:49:39 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRT_H
# define SRT_H

void	mrg_sort(int *set, size_t start, size_t end);
t_error	chk_dupl(size_t *idx, const int unit_size,
			const void *set, const size_t end);

#endif
