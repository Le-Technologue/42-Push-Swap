/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_typecasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 11:58:39 by wetieven          #+#    #+#             */
/*   Updated: 2021/04/16 12:15:18 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ptf_typecasting.h"

/*
** Those functions apply length modification when they extract our variadic
** arguments
*/

size_t	ptf_u_typecasting(va_list args, t_ptf_params *params)
{
	size_t		value;

	if (params->extend == 1)
		value = va_arg(args, unsigned long);
	else if (params->extend > 1)
		value = va_arg(args, unsigned long long);
	else if (params->shorten == 1)
		value = (unsigned short)va_arg(args, unsigned int);
	else if (params->shorten > 1)
		value = (unsigned char)va_arg(args, unsigned int);
	else
		value = va_arg(args, unsigned int);
	return (value);
}

size_t	ptf_typecasting(va_list args, t_ptf_params *params)
{
	long long	value;

	if (params->extend == 1)
		value = va_arg(args, long);
	else if (params->extend > 1)
		value = va_arg(args, long long);
	else if (params->shorten == 1)
		value = (short)va_arg(args, int);
	else if (params->shorten > 1)
		value = (char)va_arg(args, int);
	else
		value = va_arg(args, int);
	if (value < 0)
	{
		params->sign = sign_minus;
		value = -value;
	}
	return (value);
}
