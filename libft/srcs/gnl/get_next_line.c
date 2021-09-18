/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:34:53 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 15:25:12 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	gnl_line_fetch(t_marks *mark, char **line)
{
	while (mark->line_brk == -1 && mark->read_status > 0)
	{
		*line = ft_linejoin(line, &mark->rd_head[mark->rd_offset], '\0');
		if (!*line)
			return (-1);
		if (!(gnl_new_read(mark)))
			return (-1);
	}
	if (mark->read_status >= 0 && mark->line_brk != -1)
	{
		*line = ft_linejoin(line, &mark->rd_head[mark->rd_offset], '\n');
		if (!*line)
			return (-1);
		return (1);
	}
	*line = ft_linejoin(line, &mark->rd_head[mark->rd_offset], '\0');
	if (!*line)
		return (-1);
	return (0);
}

int	gnl_shutdown(int cause, t_marks **marks, t_marks *mark)
{
	t_marks	*ptr;

	if (cause <= 0)
	{
		if (*marks)
		{
			ptr = *marks;
			if (ptr != mark)
			{
				while (ptr->next && ptr->next != mark)
					ptr = ptr->next;
				if (ptr->next == mark)
					ptr->next = mark->next;
			}
			if (mark)
			{
				if (mark == *marks)
					*marks = mark->next;
				if (mark->rd_head)
					free(mark->rd_head);
				free(mark);
			}
		}
	}
	return (cause);
}

int	get_next_line(int fd, char **line)
{
	static t_marks	*marks;
	t_marks			*mark;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) || !line)
		return (-1);
	*line = NULL;
	mark = NULL;
	mark = gnl_mark_loader(fd, &marks);
	if (!mark)
		return (gnl_shutdown(-1, &marks, mark));
	return (gnl_shutdown(gnl_line_fetch(mark, line), &marks, mark));
}
