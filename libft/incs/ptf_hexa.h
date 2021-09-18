/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_hexa.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:41:49 by wetieven          #+#    #+#             */
/*   Updated: 2021/04/12 16:08:34 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTF_HEXA_H
# define PTF_HEXA_H

# include "ft_printf.h"

bool	ptf_ptr(t_vctr *vct, va_list args, t_ptf_params *params);
bool	ptf_lex(t_vctr *vct, va_list args, t_ptf_params *params);
bool	ptf_uex(t_vctr *vct, va_list args, t_ptf_params *params);

#endif
