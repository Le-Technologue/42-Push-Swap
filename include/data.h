/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:09:27 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/23 13:32:47 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_val {
	size_t	idx;
	int		val;
}	t_val;

typedef struct s_mdata {
	size_t	qty;
	t_val	*min;
	t_val	*median;
	t_val	*max;
}	t_mdata;
