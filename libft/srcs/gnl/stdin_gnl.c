/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 20:57:49 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/17 09:46:52 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int	stdin_gnl(char **line)
{
	int		read_status;
	t_vctr	*bfr;

	if (read(0, 0, 0) || !line)
		return (-1);
	*line = NULL;
	read_status = gnl_to_vctr(&bfr, 0);
	if (read_status < 0)
		return (read_status);
	vctr_push(bfr, "\0");
	*line = ft_strdup(bfr->data);
	vctr_exit(bfr);
	return (read_status);
}

/*
int	stdin_gnl(char **line)
{
	int		read_status;
	char	bfr;
	t_vctr	*vct;

	if (read(0, 0, 0) || !line)
		return (-1);
	*line = NULL;
	if (vctr_init(&vct, sizeof(char), 512))
		return (-1);
	bfr = 0;
	while (read_status > 0 && bfr != '\n')
	{
		read_status = read(0, &bfr, 1);
		vctr_push(vct, &bfr);
	}
	vctr_push(vct, "\0");
	*line = vct->data;
	vctr_exit(vct);
	return (read_status);
}
*/
