/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:12:37 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/02 14:51:39 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_error	lst_queue(t_lst *lst, t_node *new_tail)
{
	t_node	*lst_tail;

	if (!new_tail)
		return (NULL_PTR);
	if (!*lst)
		*lst = new_tail;
	else
	{
		lst_tail = last_node(*lst);
		if (!lst_tail)
			return (NULL_PTR);
		lst_tail->next = new_tail;
	}
	return (CLEAR);
}

/* For reference - the checkless way to queue our elem is that one liner :
**
** last_node(*lst)->next = new_tail;
**
** ...pretty revealing of the possibilies of C's syntax.
*/
