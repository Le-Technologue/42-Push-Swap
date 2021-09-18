/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:11:12 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/16 10:22:29 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CNV_H
# define CNV_H

/*
** Variable conversion
*/
int		ft_atoi(const char *str);
char	*ft_itoa(int nb);
char	*ft_ltoa_base(long lnb, const char *base);
int		ptr_atoi(char **str);
char	*ft_sztoa_base(unsigned long nb, const char *base);
long	ft_atol_base(const char *str, const char *base);
long	ptr_atol_base(char **str, const char *base);

#endif
