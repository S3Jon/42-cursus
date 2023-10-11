/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:22:29 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/12 16:59:37 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*aux;

	aux = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!aux)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		aux[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		aux[i + j] = s2[j];
		j++;
	}
	aux[i + j] = '\0';
	return (aux);
}
