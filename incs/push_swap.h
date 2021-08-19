/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:43:12 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/19 14:51:12 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

# define PRV_MOV game->info.prv_mov
# define PVT game->info.pvt
# define STK_A game->a.stk
# define LOAD_A game->a.load
# define TOP_A (game->a.load - 1)
# define STK_B game->b.stk
# define LOAD_B game->b.load
# define TOP_B (game->b.load - 1)

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


typedef struct s_stk {
	t_val	*stk;
	size_t	load;
}	t_stk;

typedef struct s_metadata {
	int			prv_mov;
	t_vctr		*pvt;
	_Bool		mon;
}	t_metadata;

typedef struct s_game {
	t_metadata	info;
	size_t		qty;
	t_val		**set;
	t_stk		a;
	t_stk		b;
	t_vctr		*log;
}	t_game;

#endif
