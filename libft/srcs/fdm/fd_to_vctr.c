/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_to_vctr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:29:01 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/17 09:47:02 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "typ.h"
#include "vct.h"

int	gnl_to_vctr(t_vctr **vct, int fd)
{
	int		read_status;
	char	bfr;

	if (vctr_init(vct, sizeof(char), 512) != CLEAR)
		return (-1);
	while (1)
	{
		read_status = read(fd, &bfr, 1);
		if (read_status < 0)
		{
			vctr_exit(*vct);
			return (read_status);
		}
		else if (read_status == 0 || bfr == '\n')
			return (read_status);
		if (vctr_push((*vct), &bfr))
			return (-1);
	}
}

// UNTESTED
t_error	fd_to_vctr(t_vctr **vct, int fd, size_t buf_size)
{
	ssize_t	read_status;

	if (vctr_init(vct, sizeof(char), buf_size) != CLEAR)
		return (MEM_ALLOC);
	while (1)
	{
		read_status = read(fd, (*vct)->data, buf_size);
		if (read_status == -1)
		{
			vctr_exit(*vct);
			return (FD_READ);
		}
		else if (read_status == 0)
			return (CLEAR);
		(*vct)->entries += read_status;
		if ((*vct)->entries == (*vct)->capacity)
			if (vctr_extd((*vct), buf_size) != CLEAR)
				return (MEM_ALLOC);
	}
}
