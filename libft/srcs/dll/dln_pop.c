/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dln_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:40:02 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/02 14:57:46 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dll.h"

t_error	dln_pop(t_dll *head, t_dln *popped, t_dll *tail)
{
	if (!popped)
		return (NULL_PTR);
	if (popped == *head)
		*head = popped->next;
	if (popped == *tail)
		*tail = popped->prev;
	if (popped->prev)
		popped->prev->next = popped->next;
	if (popped->next)
		popped->next->prev = popped->prev;
	return (CLEAR);
}
