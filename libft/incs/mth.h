/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mth.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:17:03 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/23 18:18:53 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTH_H
# define MTH_H

/*
** Bases
*/
size_t	ft_digit_count(long lnb, size_t base_len);
size_t	ft_udigit_count(size_t nb, size_t base_len);
int		ft_in_da_base(char c, const char *base);
size_t	ft_valid_base(const char *base);

#endif
