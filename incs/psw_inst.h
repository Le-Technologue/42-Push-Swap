/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_inst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:01:34 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/04 18:59:36 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSW_INST_H
# define PSW_INST_H

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

typedef enum e_swb_mode {
	SOLVER,
	CHECKER,
} t_swb_mode;

#endif
