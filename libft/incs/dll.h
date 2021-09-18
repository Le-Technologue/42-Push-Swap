/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:49:56 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/23 15:16:27 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_H
# define DLL_H

# include "typ.h"

typedef struct s_dln
{
	struct s_dln	*prev;
	void			*ctnt;
	struct s_dln	*next;
}					t_dln;

typedef t_dln		*t_dll;

t_dln				*new_dln(void *ctnt);
t_error				dll_push(t_dll *lst_head, t_dln *new_head);
t_error				dll_queue(t_dll *lst_tail, t_dln *new_tail);
t_error				dln_pop(t_dll *head, t_dln *popped, t_dll *tail);
//t_error			insert_dln(t_dln *prev, t_dln *new_node, t_dln *next);

#endif
