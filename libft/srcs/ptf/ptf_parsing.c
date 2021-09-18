/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:18:42 by wetieven          #+#    #+#             */
/*   Updated: 2021/04/18 21:46:34 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ptf_parsing.h"
#include "ptf_converters.h"

void	ptf_params_init(t_ptf_params *params)
{
	params->padding = pad_right_default;
	params->lftpad_toggle = false;
	params->sign = sign_none;
	params->altform_toggle = false;
	params->alt_prfx = NULL;
	params->extend = ext_none;
	params->shorten = shrt_none;
	params->width = 0;
	params->prec_toggle = false;
	params->precision = 0;
	params->type = NULL;
}

// tableau de structures // structures array // array of structures
// Initialises our functor array and could effectively act as a quasi global
// variable
//
t_ptf_format	*ptf_types_init(void)
{
	static t_ptf_format	types[] = {
		[typ_pct] = {.flag = '%', .fct = &ptf_pct},
		[typ_chr] = {.flag = 'c', .fct = &ptf_chr},
		[typ_str] = {.flag = 's', .fct = &ptf_str},
		[typ_ptr] = {.flag = 'p', .fct = &ptf_ptr},
		[typ_dec] = {.flag = 'd', .fct = &ptf_int},
		[typ_int] = {.flag = 'i', .fct = &ptf_int},
		[typ_uns] = {.flag = 'u', .fct = &ptf_uns},
		[typ_lex] = {.flag = 'x', .fct = &ptf_lex},
		[typ_uex] = {.flag = 'X', .fct = &ptf_uex},
		[typ_nbc] = {.flag = 'n', .fct = &ptf_nbc},
		[typ_end] = {.flag = '\0', .fct = NULL}
	};

	return (types);
}

// This bare bones atoi uses ** to keep our pointer moving forward throughout
// our parsing functions
//
int	ptf_atoi(char **str)
{
	unsigned int	res;

	res = 0;
	while (ft_isdigit(**str))
	{
		res = res * 10 + (**str - 48);
		(*str)++;
	}
	(*str)--;
	return (res);
}

// This loop is the tree that hides the "ifs" forest
//
t_converter	ptf_type_detect(char param, t_ptf_format *types)
{
	while (types->flag)
	{
		if (types->flag == param)
			return (types->fct);
		types++;
	}
	return (NULL);
}

// This function manages 0 and null value exceptions, either by skipping
// the printing step altogether or by overwriting the "0" string
//
bool	ptf_zero_skip(char *raw, size_t value, t_ptf_params *params)
{
	if (value == 0 && params->prec_toggle && !params->precision)
	{
		if (params->sign == sign_plus || params->sign == sign_space)
		{
			*raw = params->sign;
			params->sign = sign_none;
		}
		else if (!params->width)
			return (true);
		else
			*raw = '\0';
	}
	return (false);
}
