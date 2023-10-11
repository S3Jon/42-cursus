/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:41:53 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/12 16:59:16 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t	m;
	char	*t;

	t = s;
	m = 0;
	while (m < n)
	{
		if (t[m] == (char)c)
			return (&t[m]);
		m++;
	}
	return (0);
}
