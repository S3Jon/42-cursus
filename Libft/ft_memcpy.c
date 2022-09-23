/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:35:55 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/12 16:59:24 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t		a;
	char		*e;
	const char	*f;

	e = dest;
	f = src;
	a = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (a < len)
	{
		e[a] = f[a];
		a++;
	}
	return (e);
}
