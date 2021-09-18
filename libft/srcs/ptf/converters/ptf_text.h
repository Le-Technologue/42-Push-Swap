/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_text.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:51:01 by wetieven          #+#    #+#             */
/*   Updated: 2021/04/15 11:55:40 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTF_TEXT_H
# define PTF_TEXT_H

# include "ft_printf.h"

bool	ptf_txt_pad(t_vctr *vct, char *raw, t_ptf_params *params);
bool	ptf_pct(t_vctr *vct, va_list args, t_ptf_params *params);
bool	ptf_chr(t_vctr *vct, va_list args, t_ptf_params *params);
bool	ptf_str(t_vctr *vct, va_list args, t_ptf_params *params);

#endif
