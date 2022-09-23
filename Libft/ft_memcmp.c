/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:46:41 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/19 11:39:15 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		a;
	const char	*b;
	const char	*c;

	b = s1;
	c = s2;
	a = 0;
	if (n == 0)
		return (0);
	while (a < (n - 1))
	{
		if ((unsigned char)b[a] != (unsigned char)c[a])
			return ((unsigned char)b[a] - (unsigned char)c[a]);
		a++;
	}
	return ((unsigned char)b[a] - (unsigned char)c[a]);
}
