/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:22:40 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/02 14:49:04 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYP_H
# define TYP_H

typedef enum e_outcome {
	FAILURE,
	SUCCESS
}	t_outcome;

typedef enum e_error {
	CLEAR,
	ERROR,
	MEM_ALLOC,
	PARSE,
	NULL_PTR,
	MEM_REALLOC,
	INCOMPLETE,
	FD_OPENING,
	FD_READ,
	FD_CLOSING,
}	t_error;

#endif
