/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:08:59 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/13 14:25:56 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char const *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)s;
	if (!s || !f)
		return ;
	i = 0;
	j = ft_strlen(s);
	while (i < j)
	{
		f(i, str);
		i++;
		str++;
	}
}
