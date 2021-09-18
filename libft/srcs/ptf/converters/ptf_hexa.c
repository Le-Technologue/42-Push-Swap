/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:12:47 by wetieven          #+#    #+#             */
/*   Updated: 2021/04/15 12:45:23 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ptf_typecasting.h"
#include "ptf_padding.h"
#include "ptf_hexa.h"

bool	ptf_ptr(t_vctr *vct, va_list args, t_ptf_params *params)
{
	params->altform_toggle = true;
	params->extend = 1;
	return (ptf_lex(vct, args, params));
}

bool	ptf_lex(t_vctr *vct, va_list args, t_ptf_params *params)
{
	size_t	value;

	value = ptf_u_typecasting(args, params);
	if (!value && params->type == &ptf_ptr)
	{
		if (!params->prec_toggle || params->precision > 3)
			params->precision = 3;
		if (!ptf_txt_pad(vct, "0x0", params))
			return (false);
		return (true);
	}
	if (params->altform_toggle)
	{
		if (value == 0)
			params->altform_toggle = false;
		else
		{
			params->alt_prfx = "0x";
			if (!params->lftpad_toggle)
				params->width -= 2;
		}
	}
	if (!ptf_nbr_pad(vct, value, "0123456789abcdef", params))
		return (false);
	return (true);
}

bool	ptf_uex(t_vctr *vct, va_list args, t_ptf_params *params)
{
	size_t	value;

	value = ptf_u_typecasting(args, params);
	if (params->altform_toggle)
	{
		if (value == 0)
			params->altform_toggle = false;
		else
		{
			params->alt_prfx = "0X";
			if (!params->lftpad_toggle)
				params->width -= 2;
		}
	}
	if (!ptf_nbr_pad(vct, value, "0123456789ABCDEF", params))
		return (false);
	return (true);
}
