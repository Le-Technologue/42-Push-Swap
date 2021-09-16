/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:01:34 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/16 19:27:52 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_INST_H
# define PSW_INST_H

# include "push_swap.h"
# include "psw_push.h"
# include "psw_swap.h"
# include "psw_rotate.h"
# include "psw_rev_rotate.h"

# define INST ((t_inst_id *)(game->buf->data))

typedef void	(*t_inst)(t_game *game);

typedef struct s_inst_swtch {
	t_inst	inst;
	char	*call;
}	t_inst_swtch;

typedef enum e_inst_id {
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	END
}	t_inst_id;

t_inst_swtch	*switchboard(void);
t_inst_id		fetch_inst_id(t_inst_swtch *inst_set, char *inst_call);
void			buf_inst(t_game *game, t_inst_id inst);
void			log_inst(t_game *game);

#endif
