/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:36:49 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/17 09:32:19 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDM_H
# define FDM_H

# include "typ.h"
# include "vct.h"

t_outcome	fd_opener(char *file_path, int *fd);
t_error		fd_to_vctr(t_vctr *vct, int fd, size_t buf_size);
int			gnl_to_vctr(t_vctr **vct, int fd);
t_outcome	fd_killer(int *fd);

#endif
