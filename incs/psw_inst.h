/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:01:34 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/06 09:33:34 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_INST_H
# define PSW_INST_H

#include "psw_push.h"
#include "psw_swap.h"
#include "psw_rotate.h"
#include "psw_rev_rotate.h"

typedef	void (*t_inst)(t_game *game);

typedef struct s_inst_swtch {
	t_inst	inst;
	char	*call;
} t_inst_swtch;

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
	NaI
} t_inst_id;

t_inst	switchboard(char *inst_call);

/*typedef enum e_swb_mode {
	SOLVER,
	CHECKER,
} t_swb_mode;*/

#endif
