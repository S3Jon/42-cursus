/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:07:24 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/15 17:24:53 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	count;

	a = 0;
	while (size != 0 && a < size - 1 && src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	if (size > 0)
		dest[a] = '\0';
	count = ft_strlen(src);
	return (count);
}
