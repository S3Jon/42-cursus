/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:59:21 by jonsanch          #+#    #+#             */
/*   Updated: 2022/08/31 17:06:47 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	a;
	char	*e;

	e = b;
	a = 0;
	while (a < len)
	{
		e[a] = (unsigned char)c;
		a++;
	}
	return (e);
}
