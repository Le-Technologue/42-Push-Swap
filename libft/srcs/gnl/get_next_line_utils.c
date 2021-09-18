/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:26:22 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/04 15:33:00 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	ft_line_brk(char *str, char brk)
{
	char	*ptr;

	ptr = str;
	while (*ptr && *ptr != brk)
		ptr++;
	if (*ptr == brk)
		return (ptr - str);
	return (-1);
}

char	*ft_linejoin(char **pre, char *post, char brk)
{
	char	*ret;
	int		ret_len;
	size_t	i;

	if (!*pre)
		ret_len = ft_line_brk(post, brk) + 1;
	else
		ret_len = ft_line_brk(*pre, '\0') + ft_line_brk(post, brk) + 1;
	ret = malloc(sizeof(char) * (ret_len));
	if (!ret)
		return (NULL);
	i = 0;
	if (*pre != NULL)
	{
		while ((*pre)[i])
		{
			ret[i] = (*pre)[i];
			i++;
		}
	}
	while (*post && *post != brk)
		ret[i++] = *post++;
	ret[i] = '\0';
	free(*pre);
	return (ret);
}

t_marks	*gnl_mark_loader(int fd, t_marks **marks)
{
	t_marks	*mark;

	mark = *marks;
	while (mark)
	{
		if (fd == mark->fd)
		{
			if (mark->line_brk != -1)
			{
				mark->rd_offset += mark->line_brk + 1;
				mark->line_brk
					= ft_line_brk(&mark->rd_head[mark->rd_offset], '\n');
			}
			return (mark);
		}
		mark = mark->next;
	}
	return (gnl_add_mark(fd, marks));
}

int	gnl_new_read(t_marks *mark)
{
	mark->rd_offset = 0;
	mark->read_status = read(mark->fd, mark->rd_head, BUFFER_SIZE);
	if (mark->read_status == -1)
		return (0);
	mark->rd_head[mark->read_status] = '\0';
	mark->line_brk = ft_line_brk(mark->rd_head, '\n');
	return (1);
}

t_marks	*gnl_add_mark(int fd, t_marks **marks)
{
	t_marks	*new_mark;

	new_mark = malloc(sizeof(t_marks));
	if (!new_mark)
		return (NULL);
	new_mark->rd_head = malloc(BUFFER_SIZE + 1);
	if (!new_mark->rd_head)
		return (NULL);
	new_mark->fd = fd;
	if (!(gnl_new_read(new_mark)))
		return (NULL);
	new_mark->next = *marks;
	*marks = new_mark;
	return (new_mark);
}
