/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:09:27 by wetieven          #+#    #+#             */
/*   Updated: 2021/07/21 18:11:05 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_val {
	size_t	idx;
	int		val;
}	t_val;

typedef struct s_metadata {
	size_t	qty;
	t_val	*min;
	t_val	*med;
	t_val	*max;
}	t_metadata;

typedef struct s_stck {
	t_dll	*top;
	t_dll	*bottom;
}	t_stck;

typedef struct s_game {
	t_metadata	info;
	t_stck		a;
	t_stck		b;
	t_val		*nbrs;
}	t_game;
