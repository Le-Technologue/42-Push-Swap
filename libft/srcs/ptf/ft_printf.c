/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:18:30 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/15 15:14:06 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ptf_parsing.h"
#include "ptf_converters.h"

// Retrieves width and precision values provided by variable arguments
// signaled by * flags.
// Negative precision values are resetting precision parameters.
//
int	ptf_star_treatment(t_ptf_params *params, va_list args, char mode)
{
	int	res;

	res = va_arg(args, int);
	if (mode == 'w')
	{
		if (res < 0)
		{
			params->lftpad_toggle = true;
			res = -res;
		}
	}
	else if (mode == 'p')
	{
		if (res < 0)
		{
			params->prec_toggle = false;
			res = 0;
		}
	}
	return (res);
}

bool	ptf_parse_flags(char **src, t_ptf_params *params)
{
	while (**src)
	{
		if (**src == '-')
			params->lftpad_toggle = true;
		else if (**src == '0')
			params->padding = pad_right_zero;
		else if (**src == ' ' && !params->sign)
			params->sign = sign_space;
		else if (**src == '+')
			params->sign = sign_plus;
		else if (**src == '#')
			params->altform_toggle = true;
		else if (**src == 'l')
			params->extend++;
		else if (**src == 'h')
			params->shorten++;
		else
			return (true);
		(*src)++;
	}
	return (false);
}

// This convoluted loop is based on our analysis of printf behavior, undefined
// and otherwise, when it comes to parsing parameters and variable types.
// It may probably be an actual "do while" in the actual printf.
//
bool	ptf_typeset(
	char **src, t_ptf_params *params, va_list args, t_ptf_format *types)
{
	while (1)
	{
		(*src)++;
		ptf_parse_flags(src, params);
		if (ft_isdigit(**src))
			params->width = ptf_atoi(src);
		if (**src == '*')
			params->width = ptf_star_treatment(params, args, 'w');
		if (**src == '.')
		{
			params->prec_toggle = true;
			params->precision = 0;
			if (*(++(*src)) == '*')
				params->precision = ptf_star_treatment(params, args, 'p');
			if (ft_isdigit(**src))
				params->precision = ptf_atoi(src);
		}
		if (!(**src) || ptf_type_detect(**src, types))
			break ;
	}
	params->type = ptf_type_detect(**src, types);
	if (!params->type)
		return (false);
	return (true);
}

int	ptf_parser(t_vctr *vct, char **src, va_list args)
{
	t_ptf_params	params;
	t_ptf_format	*types;

	types = ptf_types_init();
	while (**src)
	{
		if (**src == '%')
		{
			ptf_params_init(&params);
			if (!ptf_typeset(src, &params, args, types))
				return (false);
			if (!((params.type)(vct, args, &params)))
				return (false);
		}
		else
			if (vctr_push(vct, *src) != CLEAR)
				return (false);
		(*src)++;
	}
	return (vct->entries);
}

int	ft_printf(const char *src, ...)
{
	va_list	args;
	int		prt_len;
	t_vctr	*vct;

	va_start(args, src);
	vctr_init(&vct, sizeof(char), 512);
	if (!vct)
		return (0);
	prt_len = ptf_parser(vct, (char **)&src, args);
	if (prt_len)
		write(1, vct->data, vct->entries);
	vctr_exit(vct);
	va_end(args);
	return (prt_len);
}
