/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 16:39:37 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/09 16:22:42 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "vct.h"

void	vctr_exit(t_vctr *vct)
{
	free(vct->data);
	free(vct);
}

t_error	vctr_extd(t_vctr *vct, size_t increase)
{
	void	*old_data;
	size_t	old_capacity;

	old_data = vct->data;
	old_capacity = vct->capacity;
	vct->capacity += increase;
	vct->data = ft_calloc(vct->unit_size, vct->capacity);
	if (!vct->data)
		return (MEM_ALLOC);
	ft_memcpy(vct->data, old_data, old_capacity * vct->unit_size);
	free(old_data);
	return (CLEAR);
}

t_error	vctr_push(t_vctr *vct, void *data)
{
	if (vct->entries == vct->capacity)
		if (vctr_extd(vct, vct->init_count))
			return (MEM_ALLOC);
	ft_memcpy(vct->data + vct->entries * vct->unit_size, data, vct->unit_size);
	vct->entries++;
	return (CLEAR);
}

t_error	str_to_vctr(t_vctr *vct, char *str)
{
	if (!str)
		return (NULL_PTR);
	while (*str)
	{
		if (vctr_push(vct, str++))
			return (MEM_ALLOC);
	}
	return (CLEAR);
}

t_error	vctr_init(t_vctr **vct, size_t unit_size, size_t init_count)
{
	*vct = malloc(sizeof(t_vctr));
	if (!*vct)
		return (MEM_ALLOC);
	(*vct)->data = ft_calloc(unit_size, init_count);
	if (!(*vct)->data)
		return (MEM_ALLOC);
	(*vct)->entries = 0;
	(*vct)->capacity = init_count;
	(*vct)->unit_size = unit_size;
	(*vct)->init_count = init_count;
	return (CLEAR);
}
