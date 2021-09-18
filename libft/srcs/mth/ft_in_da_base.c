/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_da_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wetieven <wetieven@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:06:10 by wetieven          #+#    #+#             */
/*   Updated: 2021/05/03 16:56:39 by wetieven         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_in_da_base(const char c, const char *base)
{
	char	*ptr;

	ptr = (char *)base;
	while (*ptr)
	{
		if (c == *ptr)
			return (ptr - base);
		ptr++;
	}
	return (-1);
}
/* Decided against this implementation to limit function calls
** for atoi_base we need an index for calculations, and not a pointer to the
** char itself. Hence the specialised implementation.
ptr = ft_strchr(base, c);
if (!ptr)
	return (-1);
return (ptr - base);
*/
