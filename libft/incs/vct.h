/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:18:02 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/07 14:00:07 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VCT_H
# define VCT_H

# include <stddef.h>

typedef struct s_vctr {
	void			*data;
	size_t			entries;
	size_t			unit_size;
	size_t			init_count;
	size_t			capacity;
}	t_vctr;

t_error	vctr_init(t_vctr **vct, size_t unit_size, size_t init_count);
t_error	vctr_extd(t_vctr *vct, size_t increase);
t_error	vctr_push(t_vctr *vct, void *data);
t_error	str_to_vctr(t_vctr *vct, char *str);
void	vctr_exit(t_vctr *vct);

#endif
