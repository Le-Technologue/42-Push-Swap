/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:35:25 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/16 21:22:59 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 512

/*
** Bookmark structure : granting continuity between gnl calls,
** linking these in a list allows for multi fd management
*/
typedef struct s_marks
{
	int				fd;
	char			*rd_head;
	int				rd_offset;
	int				read_status;
	int				line_brk;
	struct s_marks	*next;
}					t_marks;

int					get_next_line(int fd, char **line);
int					stdin_gnl(char **line);

/*
** Modular strlen : Returns the position of a character in a string
** or -1 if it's missing
*/
int					ft_line_brk(char *str, char brk);

/*
** Modular strjoin : Appends the "post" string up to the brk character
** to the "pre" string and frees the former "pre "chain
*/
char				*ft_linejoin(char **pre, char *post, char brk);

/*
** Fetches the bookmark to a specific fd
*/
t_marks				*gnl_mark_loader(int fd, t_marks **marks);

/*
** Puts a new bookmark on the bookmark pile
*/
t_marks				*gnl_add_mark(int fd, t_marks **marks);

/*
** Refreshes the buffer (rd_head) with a new call to the read function
*/
int					gnl_new_read(t_marks *mark);

/*
** Parses out the buffer and returns completed lines
*/
int					gnl_line_fetch(t_marks *mark, char **line);

/*
** Clears and removes a bookmark from the list when its fd reaches EOF
** or when an error arises
*/
int					gnl_shutdown(int cause, t_marks **marks, t_marks *mark);

#endif
