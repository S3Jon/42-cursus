/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:01:11 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/13 14:27:43 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_fdputnmb(int n, int fd)
{
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_fdputnmb((8 + 48), fd);
		return ;
	}
	if (n < 0)
	{
		ft_fdputnmb(45, fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_fdputnmb(((n % 10) + 48), fd);
	}
	else if (n < 10)
		ft_fdputnmb((n + 48), fd);
}
