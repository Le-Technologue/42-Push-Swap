/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_integers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:08:44 by wetieven          #+#    #+#             */
/*   Updated: 2021/04/15 12:46:19 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ptf_typecasting.h"
#include "ptf_padding.h"
#include "ptf_integers.h"

bool	ptf_nbc(t_vctr *vct, va_list args, t_ptf_params *params)
{
	void	*nbc;

	(void)params;
	nbc = va_arg(args, void *);
	if (!nbc)
		return (false);
	if (params->extend == 1)
		*(long *)nbc = vct->entries;
	else if (params->extend > 1)
		*(long long *)nbc = vct->entries;
	else if (params->shorten == 1)
		*(short *)nbc = vct->entries;
	else if (params->shorten > 1)
		*(signed char *)nbc = vct->entries;
	else
		*(int *)nbc = vct->entries;
	return (true);
}

bool	ptf_uns(t_vctr *vct, va_list args, t_ptf_params *params)
{
	size_t	value;

	value = ptf_u_typecasting(args, params);
	params->altform_toggle = false;
	if (!ptf_nbr_pad(vct, value, "0123456789", params))
		return (false);
	return (true);
}

bool	ptf_int(t_vctr *vct, va_list args, t_ptf_params *params)
{
	size_t	value;

	value = ptf_typecasting(args, params);
	params->altform_toggle = false;
	if (!ptf_nbr_pad(vct, value, "0123456789", params))
		return (false);
	return (true);
}
