/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:07:54 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/02 14:57:16 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dll.h"

t_error	dll_push(t_dll *lst_head, t_dln *new_head)
{
	if (!new_head)
		return (NULL_PTR);
	new_head->prev = NULL;
	new_head->next = *lst_head;
	*lst_head = new_head;
	return (CLEAR);
}
