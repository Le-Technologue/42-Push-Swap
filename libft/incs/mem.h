/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:15:59 by wetieven          #+#    #+#             */
/*   Updated: 2021/08/06 12:34:47 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <unistd.h>
# include "typ.h"

/*
** Memory check
*/
void	*ft_memchr(const void *src, int c, size_t len);
int		ft_memcmp(const void *src, const void *cmp, size_t len);

/*
** Memory initialisation
*/
void	*ft_memset(void *src, int c, size_t len);
void	ft_bzero(void *src, size_t len);

/*
** Memory manipulation
*/
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_swap(void *a, void *b);
t_error	rot_arr_l_to_r(void *arr, size_t unit_size, size_t len, size_t span);
t_error	rot_arr_r_to_l(void *arr, size_t unit_size, size_t len, size_t span);

/*
** Memory allocation
*/
void	*ft_calloc(size_t count, size_t size);

#endif
