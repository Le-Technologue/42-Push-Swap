/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:29:10 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/22 19:33:57 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_node	*last_node(t_lst lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}
