/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:36:13 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/22 18:22:13 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lst.h"

t_lst	lst_map(t_lst lst, void *(*fct)(void *), t_error (*del)(void *))
{
	t_lst	ret;
	t_node	*ptr;
	t_node	*new_elem;

	if (!lst)
		return (NULL);
	ret = new_node((*fct)(lst->ctnt));
	if (!ret)
		return (NULL);
	lst = lst->next;
	ptr = ret;
	while (lst)
	{
		new_elem = new_node((*fct)(lst->ctnt));
		if (!new_elem)
		{
			free_lst(&ret, del);
			return (NULL);
		}
		ptr->next = new_elem;
		lst = lst->next;
		ptr = ptr->next;
	}
	return (ret);
}
