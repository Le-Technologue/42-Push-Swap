/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_padding.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:57:50 by wetieven          #+#    #+#             */
/*   Updated: 2021/04/16 13:02:28 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTF_PADDING_H
# define PTF_PADDING_H

# include "ft_printf.h"
# include "ptf_text.h"

bool	ptf_prt_sign(t_vctr *vct, t_ptf_params *params);
bool	ptf_prt_nbr(t_vctr *vct,
			char *raw_str, size_t raw_len, t_ptf_params *params);
bool	ptf_lft_pad(t_vctr *vct,
			char *raw_str, size_t raw_len, t_ptf_params *params);
bool	ptf_rgt_pad(t_vctr *vct,
			char *raw_str, size_t raw_len, t_ptf_params *params);
bool	ptf_nbr_pad(t_vctr *vct,
			size_t value, char *base, t_ptf_params *params);

#endif
