/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:35:46 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 18:39:48 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "dsp.h"

void	ft_recursive_putdigit_fd(long lnb, int fd)
{
	if (lnb >= 10)
		ft_recursive_putdigit_fd(lnb / 10, fd);
	ft_putchar_fd(lnb % 10 + 48, fd);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long	lnb;

	lnb = nb;
	if (lnb < 0)
	{
		ft_putchar_fd('-', fd);
		lnb = -lnb;
	}
	ft_recursive_putdigit_fd(lnb, fd);
}
