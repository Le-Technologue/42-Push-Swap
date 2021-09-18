/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:18:30 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/02 14:57:31 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dll.h"

t_error	dll_queue(t_dll *lst_tail, t_dln *new_tail)
{
	if (!new_tail)
		return (NULL_PTR);
	new_tail->prev = *lst_tail;
	new_tail->next = NULL;
	*lst_tail = new_tail;
	return (CLEAR);
}
