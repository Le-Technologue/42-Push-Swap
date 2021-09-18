/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:55:57 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/15 15:47:55 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ptf_padding.h"
#include "ptf_parsing.h"
#include "ptf_text.h"

/*
** These functions are editing and printing our variables accordingly to our
** desired parameters inside our vector.
*/

bool	ptf_prt_sign(t_vctr *vct, t_ptf_params *params)
{
	if (params->sign != sign_none)
	{
		if (vctr_push(vct, &params->sign) != CLEAR)
			return (false);
		params->sign = sign_none;
	}
	return (true);
}

bool	ptf_prt_nbr(t_vctr *vct,
			char *raw_str, size_t raw_len, t_ptf_params *params)
{
	if (!ptf_prt_sign(vct, params))
		return (false);
	if (params->altform_toggle)
	{
		str_to_vctr(vct, params->alt_prfx);
		params->altform_toggle = false;
	}
	while (params->precision-- > (int)raw_len)
		if (vctr_push(vct, "0") != CLEAR)
			return (false);
	if (params->altform_toggle)
		str_to_vctr(vct, params->alt_prfx);
	if (str_to_vctr(vct, raw_str) != CLEAR)
		return (false);
	return (true);
}

bool	ptf_lft_pad(t_vctr *vct,
			char *raw_str, size_t raw_len, t_ptf_params *params)
{
	size_t	start;

	start = vct->entries;
	if (!ptf_prt_nbr(vct, raw_str, raw_len, params))
		return (false);
	while ((int)(vct->entries - start) < params->width)
		if (vctr_push(vct, " ") != CLEAR)
			return (false);
	return (true);
}

bool	ptf_rgt_pad(t_vctr *vct,
			char *raw_str, size_t raw_len, t_ptf_params *params)
{
	if (params->padding == pad_right_zero && !params->prec_toggle)
	{
		if (!ptf_prt_sign(vct, params))
			return (false);
		if (params->altform_toggle)
		{
			str_to_vctr(vct, params->alt_prfx);
			params->altform_toggle = false;
		}
	}
	while (params->width > params->precision && params->width > (int)raw_len)
	{
		if (params->prec_toggle)
		{
			if (vctr_push(vct, " ") != CLEAR)
				return (false);
		}
		else
			if (vctr_push(vct, &params->padding) != CLEAR)
				return (false);
		params->width--;
	}
	if (!ptf_prt_nbr(vct, raw_str, raw_len, params))
		return (false);
	return (true);
}

bool	ptf_nbr_pad(t_vctr *vct,
			size_t value, char *base, t_ptf_params *params)
{
	size_t	raw_len;
	char	*raw_str;

	raw_str = ft_sztoa_base(value, base);
	if (ptf_zero_skip(raw_str, value, params))
	{
		free(raw_str);
		return (true);
	}
	raw_len = ft_strlen(raw_str);
	if (params->sign != sign_none)
	{
		raw_len++;
		params->precision++;
	}
	if (params->lftpad_toggle)
	{
		if (!ptf_lft_pad(vct, raw_str, raw_len, params))
			return (false);
	}
	else
		if (!ptf_rgt_pad(vct, raw_str, raw_len, params))
			return (false);
	free(raw_str);
	return (true);
}
