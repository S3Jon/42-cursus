/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:26:03 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/12 16:59:46 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	j;
	size_t	k;

	k = 0;
	j = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	if (len == 0)
	{
		if (str[0] == '\0' && to_find[0] == '\0')
			return ((char *)&str[0]);
		return (0);
	}
	while (str[j] && j < len)
	{
		k = 0;
		while (str[j + k] == to_find[k] && j + k < len)
		{
			k++;
			if (to_find[k] == '\0')
				return ((char *)&str[j]);
		}
		j++;
	}
	return (0);
}
