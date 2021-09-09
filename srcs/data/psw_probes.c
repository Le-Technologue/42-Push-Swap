/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_probes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:26:41 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/09 22:21:25 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_inst.h"
#include "psw_inst_mngr.h"
#include "psw_probes.h"

t_stk	*stk_ptr(t_game *game, t_mode step)
{
	t_stk	*ptr;

	if (step <= A)
		ptr = &game->a;
	else
		ptr = &game->b;
	return (ptr);
}

t_inst_mngr	steer_rot(t_stk *ptr, size_t low, size_t high)
{
	size_t	lower;
	size_t	higher;

	lower = 0;
	while (lower < (ptr->load - 1) / 2
			&& ptr->stk[lower].key < low && ptr->stk[lower].key > high)
		lower++;
	higher = ptr->load - 1;
	while (higher >= (ptr->load - 1) / 2
			&& ptr->stk[higher].key < low && ptr->stk[higher].key > high)
		higher--;
	if (lower > ptr->load - 1 - higher)
		return (rot);
	else
		return (rrot);
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

/*
size_t	psw_nxtkey_idx(t_val *ptr, size_t load, size_t *sought, size_t nxt)
{
	size_t	i;
	size_t	vain_queries;

	vain_queries = 0;
	while (vain_queries < 2)
	{
		i = 0;
		while (ptr[i].key != *sought && i < load - 1)
			i++;
		if (ptr[i].key == *sought) 
			return (i);
		if (nxt < *sought)
		{
			*sought -= 1;
			nxt--;
		}
		else
		{
			*sought += 1;
			nxt++;
		}
		vain_queries++;
	}
	return (ptr->load);
}
*/

_Bool	sorted(t_game *game, t_mode stack, size_t low)
{
	size_t i;
	t_stk *ptr;

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
		return 1;
	else
		return 0;
}

/*
_Bool	chk_B(t_game *game)
{
	size_t i;

	i = 0;
	while (LOAD_B >= 2 && i < TOP_B && STK_B[i + 1].key == STK_B[i].key + 1)
		i++;
	if (i == TOP_B || LOAD_B < 2)
		return 1;
	else
		return 0;
}

_Bool	chk_A(t_game *game)
{
	size_t i;

	i = 0;
	while (LOAD_A >= 2 && i < TOP_A && STK_A[i + 1].key == STK_A[i].key - 1)
		i++;
	if (i == TOP_A || LOAD_A < 2)
		return 1;
	else
		return 0;
}
*/
