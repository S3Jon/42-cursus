/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:46 by jonsanch          #+#    #+#             */
/*   Updated: 2022/11/15 17:20:31 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conditionale(unsigned int a, char b)
{
	if (a <= 9 && a >= 0)
		return (ft_putchar(a + '0'));
	if (a >= 10 && a <= 16)
		return (ft_putchar((a - 10) + (b - 23)));
	return (0);
}

int	ft_puthex(size_t a, char b)
{
	int	cont;

	cont = 0;
	if (a >= 16)
	{
		cont += ft_puthex(a / 16, b);
		cont += ft_conditionale((a % 16), b);
	}
	if (a < 16 && a >= 0)
		cont += (ft_conditionale(a, b));
	return (cont);
}
