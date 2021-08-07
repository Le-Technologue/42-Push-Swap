/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:43:12 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/07 13:41:59 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include "libft.h"

typedef enum e_fid {
	MAIN_START,
	PSW_PARSING,
	PSW_GAME,
	MAIN_END
}	t_fid;

typedef struct s_val {
	size_t	key;
	int		val;
}	t_val;

typedef struct s_metadata {
	size_t	qty;
	t_val	*min;
	t_val	*med;
	t_val	*max;
}	t_metadata;

typedef struct s_stk {
	t_val	*stk;
	size_t	top;
}	t_stk;

typedef struct s_game {
	t_metadata	info;
	t_stk		a;
	t_stk		b;
	t_val		*set;
	t_vctr		*cue;
}	t_game;

#endif
