/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:19:56 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/02 14:53:06 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_error	lst_iter(t_lst lst, t_error (*fct)(void *))
{
	t_error	ret;

	ret = NULL_PTR;
	while (lst)
	{
		ret = (*fct)(lst->ctnt);
		lst = lst->next;
	}
	return (ret);
}
