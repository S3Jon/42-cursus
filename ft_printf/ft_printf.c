/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:17:10 by jonsanch          #+#    #+#             */
/*   Updated: 2022/11/15 17:17:22 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printvar(const char *str, int pos, va_list ap, int *val)
{
	if (str[pos] == '%')
		*val += ft_putchar('%');
	else if (str[pos] == 'd' || str[pos] == 'i')
		*val += ft_putnbr(va_arg(ap, int));
	else if (str[pos] == 's')
		*val += ft_putstr(va_arg(ap, char *));
	else if (str[pos] == 'c')
		*val += ft_putchar(va_arg(ap, int));
	else if (str[pos] == 'u')
		*val += ft_putunbr(va_arg(ap, unsigned int));
	else if (str[pos] == 'x' || str[pos] == 'X')
		*val += ft_puthex(va_arg(ap, unsigned int), str[pos]);
	else if (str[pos] == 'p')
	{
		*val += ft_putstr("0x");
		*val += ft_puthex(va_arg(ap, size_t), 'x');
	}
}

int	ft_printf(const char *str, ...)
{
	int		val;
	int		pos;
	va_list	ap;

	va_start(ap, str);
	val = 0;
	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] != '%')
			val += ft_putchar(str[pos]);
		else
			ft_printvar(str, ++pos, ap, &val);
		pos++;
	}
	va_end(ap);
	return (val);
}

//int main()
//{
//	int a = ft_printf("Hola %d buenos %c dias %s que %%
// tal %u z % %", 42, 'a', "aló", -500);
//	printf("\n|%d|\n", a);
//	return (0);
//}