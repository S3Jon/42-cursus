/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:16:25 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/12 16:59:33 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int to_find)
{
	int	j;

	j = 0;
	while (to_find > 127)
		to_find -= 128;
	if (to_find == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[j] != '\0')
	{
		if (str[j] == to_find)
			return ((char *)&str[j]);
		j++;
	}
	return (0);
}
