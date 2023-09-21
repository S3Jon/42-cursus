/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:26:03 by jonsanch          #+#    #+#             */
/*   Updated: 2023/09/21 12:45:18 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	j;
	size_t	k;

	k = 0;
	j = 0;
	while (str[j] && j < len)
	{
		k = 0;
		while (str[j + k] == to_find[k] && j + k < len)
		{
			k++;
			if (to_find[k] == '\0')
				return (1);
		}
		j++;
	}
	return (0);
}
