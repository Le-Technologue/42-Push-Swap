/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:25:56 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/23 13:52:13 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main(int ac, char **av)
{
	int		i;
	t_mdata	metadata;
	t_val	val[ac - 1];

	metadata.qty = ac - 1;
	i = 0;
	while (i < metadata.qty)
	{
		val[i].val = ft_atoi(av[i + 1]);
		//new_dln
		i++;
	}
}
