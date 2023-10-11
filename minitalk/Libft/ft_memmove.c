/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:02:48 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/12 16:59:26 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*fin;
	char	*init;
	size_t	i;

	fin = (char *)dst;
	init = (char *)src;
	i = 0;
	if ((!dst && !src) || len == 0)
		return (dst);
	if (init < fin && i < len)
	{
		while (len--)
			fin[len] = init[len];
	}
	else
	{
		while (i < len)
		{
			fin[i] = init[i];
			i++;
		}
	}
	return (dst);
}
