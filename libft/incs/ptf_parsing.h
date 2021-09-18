/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:29:34 by wetieven          #+#    #+#             */
/*   Updated: 2021/04/15 10:29:56 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTF_PARSING_H
# define PTF_PARSING_H

# include "ft_printf.h"

void			ptf_params_init(t_ptf_params *params);
t_ptf_format	*ptf_types_init(void);
int				ptf_atoi(char **str);
t_converter		ptf_type_detect(char param, t_ptf_format *types);
bool			ptf_zero_skip(char *raw, size_t value, t_ptf_params *params);

#endif
