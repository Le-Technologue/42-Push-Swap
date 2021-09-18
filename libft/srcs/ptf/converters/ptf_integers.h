/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_integers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:48:17 by wetieven          #+#    #+#             */
/*   Updated: 2021/04/12 16:09:32 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTF_INTEGERS_H
# define PTF_INTEGERS_H

# include "ft_printf.h"

bool	ptf_nbc(t_vctr *vct, va_list args, t_ptf_params *params);
bool	ptf_uns(t_vctr *vct, va_list args, t_ptf_params *params);
bool	ptf_int(t_vctr *vct, va_list args, t_ptf_params *params);

#endif
