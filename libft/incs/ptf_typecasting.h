/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_typecasting.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:01:35 by wetieven          #+#    #+#             */
/*   Updated: 2021/04/15 12:06:18 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTF_TYPECASTING_H
# define PTF_TYPECASTING_H

# include "ft_printf.h"

size_t	ptf_u_typecasting(va_list args, t_ptf_params *params);
size_t	ptf_typecasting(va_list args, t_ptf_params *params);

#endif
