/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:27:39 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/22 14:46:41 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_bestsz(char const *s, size_t i, size_t len)
{
	if (ft_strlen(&s[i]) <= len)
		return (ft_strlen(&s[i]));
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = start;
	j = 0;
	if (ft_strlen(s) < start)
	{
		str = (char *)malloc(1);
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(1 + ft_bestsz(s, i, len));
	if (!str || len < 0)
		return (0);
	while (s[i + j] != '\0' && j < len)
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
