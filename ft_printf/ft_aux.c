/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:49:41 by jonsanch          #+#    #+#             */
/*   Updated: 2022/11/15 17:00:39 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putunbr(unsigned int a)
{
	int	cont;

	cont = 0;
	if (a > 9)
		cont += ft_putunbr(a / 10);
	cont += ft_putchar((a % 10) + '0');
	return (cont);
}

int	ft_putnbr(int nb)
{
	int	cont;

	cont = 0;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		cont++;
	}
	if (nb >= 10)
	{
		cont += ft_putnbr(nb / 10);
		cont += ft_putchar((nb % 10) + 48);
	}
	else if (nb < 10)
		cont += ft_putchar(nb + 48);
	return (cont);
}
