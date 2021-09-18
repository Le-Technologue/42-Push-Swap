/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:35:43 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/02 14:52:42 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lst.h"

t_error	free_lst(t_lst *lst, t_error (*free_ctnt)(void *))
{
	t_node	*temp;
	t_node	*ptr;
	t_error	ret;

	ret = NULL_PTR;
	if (free_ctnt)
	{
		ptr = *lst;
		temp = ptr;
		while (temp)
		{
			ptr = temp;
			temp = ptr->next;
			ret = free_node(ptr, free_ctnt);
		}
		*lst = NULL;
	}
	return (ret);
}
