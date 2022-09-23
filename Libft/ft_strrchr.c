/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:20:21 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/22 14:46:32 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	j;
	int	last;

	j = 0;
	last = 0;
	if ((char)c == '\0')
	{
		if (ft_strlen(str) == 0)
			return ((char *)&str[0]);
		else
			return ((char *)&str[ft_strlen(str)]);
	}
	if (str[0] == '\0')
		return (NULL);
	while (str[j] != '\0')
	{
		if (str[j] == (char)c)
			last = j;
		j++;
	}
	if (last == 0 && str[0] != (char)c)
		return (NULL);
	return ((char *)&str[last]);
}
