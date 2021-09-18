/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:09:06 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/23 17:11:56 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHR_H
# define CHR_H

/*
** Char check
*/
int	ft_isalpha(int c);
int	ft_isupper(int c);
int	ft_islower(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_isspace(int c);

/*
** Char alteration
*/
int	ft_toupper(int c);
int	ft_tolower(int c);

#endif
