/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:04:28 by wetieven          #+#    #+#             */
/*   Updated: 2021/09/15 15:17:49 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ptf_text.h"

bool	ptf_txt_pad(t_vctr *vct, char *raw, t_ptf_params *params)
{
	char		*ptr;

	ptr = raw;
	if (params->lftpad_toggle)
	{
		while (params->precision--)
			if (vctr_push(vct, ptr++) != CLEAR)
				return (false);
		while (params->width-- > (ptr - raw))
			if (vctr_push(vct, " ") != CLEAR)
				return (false);
	}
	else
	{
		while (params->width-- > params->precision)
			if (vctr_push(vct, &params->padding) != CLEAR)
				return (false);
		while (params->precision--)
			if (vctr_push(vct, ptr++) != CLEAR)
				return (false);
	}
	return (true);
}

bool	ptf_pct(t_vctr *vct, va_list args, t_ptf_params *params)
{
	char	pct;

	pct = '%';
	(void)args;
	params->precision = 1;
	if (!ptf_txt_pad(vct, &pct, params))
		return (false);
	return (true);
}

bool	ptf_chr(t_vctr *vct, va_list args, t_ptf_params *params)
{
	char	c;

	c = va_arg(args, int);
	params->precision = 1;
	if (!ptf_txt_pad(vct, &c, params))
		return (false);
	return (true);
}

bool	ptf_str(t_vctr *vct, va_list args, t_ptf_params *params)
{
	void	*raw_str;
	size_t	raw_len;

	raw_str = va_arg(args, char *);
	if (!raw_str)
	{
		raw_str = "(null)";
		if (!params->prec_toggle || params->precision > 6)
			params->precision = 6;
	}
	else
	{
		if (params->prec_toggle && !params->precision)
			raw_str = "";
		raw_len = ft_strlen(raw_str);
		if (!params->prec_toggle || params->precision > (int)raw_len)
			params->precision = raw_len;
	}
	if (!ptf_txt_pad(vct, raw_str, params))
		return (false);
	return (true);
}
