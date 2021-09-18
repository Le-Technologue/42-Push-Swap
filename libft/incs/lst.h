/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:14:17 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/23 10:44:04 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include <stddef.h>
# include "typ.h"

typedef struct s_node
{
	void			*ctnt;
	struct s_node	*next;
}					t_node;

typedef t_node	*t_lst;

/*
** List check
*/
size_t				lst_size(t_lst lst);
t_node				*last_node(t_lst lst);

/*
** List manipulation
*/
t_node				*new_node(void *ctnt);
t_error				lst_push(t_lst *lst, t_node *new_head);
t_error				lst_queue(t_lst *lst, t_node *new_tail);
t_error				lst_iter(t_lst lst, t_error (*fct)(void *));
t_lst				lst_map(t_lst lst, void *(*fct)(void *),
						t_error (*del)(void *));
t_error				free_node(t_node *to_free, t_error (*free_ctnt)(void *));
t_error				free_lst(t_lst *lst, t_error (*free_ctnt)(void *));

#endif
