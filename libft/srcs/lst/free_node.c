/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:40:37 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/02 14:52:09 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lst.h"

t_error	free_node(t_node *to_free, t_error (*free_ctnt)(void *))
{
	t_error	ret;

	ret = NULL_PTR;
	if (free_ctnt)
		ret = (*free_ctnt)(to_free->ctnt);
	free(to_free);
	return (ret);
}
