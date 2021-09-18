/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:36:01 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/02 14:50:15 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_error	lst_push(t_lst *lst, t_node *new_head)
{
	if (!new_head)
		return (NULL_PTR);
	new_head->next = *lst;
	*lst = new_head;
	return (CLEAR);
}
