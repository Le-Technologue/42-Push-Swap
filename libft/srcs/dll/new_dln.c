/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dln.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:57:27 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/23 09:53:19 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dll.h"

t_dln	*new_dln(void *ctnt)
{
	t_dln	*new_node;

	new_node = malloc(sizeof(t_dln));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->ctnt = ctnt;
	new_node->next = NULL;
	return (new_node);
}
