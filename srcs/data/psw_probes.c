/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_probes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:26:41 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/15 17:58:13 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"
#include "psw_probes.h"

t_stk	*stk_ptr(t_game *game, t_step step)
{
	t_stk	*ptr;

	if (step <= A)
		ptr = &game->a;
	else
		ptr = &game->b;
	return (ptr);
}

size_t	psw_srch_key(t_stk *ptr, size_t load, size_t sought)
{
	size_t	i;

	i = 0;
	while (ptr->stk[i].key != sought && i < load - 1)
		i++;
	if (ptr->stk[i].key == sought)
		return (i);
	return (ptr->load);
}

t_stk	*psw_key_locat(t_game *game, size_t sought)
{
	if (psw_srch_key(&game->a, LOAD_A, sought) < LOAD_A)
		return (&game->a);
	else
		return (&game->b);
}

_Bool	sorted(t_game *game, t_step stack, size_t low)
{
	size_t	i;
	t_stk	*ptr;

	ptr = stk_ptr(game, stack);
	i = low;
	if (stack <= A)
	{
		while (i < (ptr->load - 1)
			&& ptr->stk[i + 1].key == ptr->stk[i].key - 1)
			i++;
	}
	else
		while (i < (ptr->load - 1)
			&& ptr->stk[i + 1].key == ptr->stk[i].key + 1)
			i++;
	if (i == (ptr->load - 1) || (ptr->load - 1) - low == 0)
		return (1);
	else
		return (0);
}
