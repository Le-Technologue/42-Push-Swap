/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:43:12 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/16 10:49:01 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

// Metadata
# define GAME_QTY game->info.qty
# define PRV_MOV game->info.prv_mov
# define MONITORING game->info.mon

// Stack A
# define LOAD_A game->a.load
# define TOP_A (game->a.load - 1)

# define STK_A game->a.stk
# define UNDR_A game->a.under

// Stack B
# define LOAD_B game->b.load
# define TOP_B (game->b.load - 1)

# define STK_B game->b.stk
# define UNDR_B game->b.under

typedef enum e_fid {
	PSW_PARSING,
	PSW_GAME,
	CHECKER,
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
	size_t		qty;
	int			prv_mov;
	_Bool		mon;
}	t_metadata;

typedef struct s_game {
	t_metadata	info;
	t_val		**set;
	t_stk		a;
	t_stk		b;
	t_vctr		*buf;
	t_vctr		*log;
}	t_game;

#endif
