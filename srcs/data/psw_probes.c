/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_probes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 11:26:41 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/24 11:29:16 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "psw_probes.h"

_Bool	chk_A(t_game *game)
{
	size_t i;

	i = 0;
	while (LOAD_A >= 2 && i < TOP_A && STK_A[i + 1].key < STK_A[i].key)
		i++;
	if (i == TOP_A)
		return 1;
	else
		return 0;
}
