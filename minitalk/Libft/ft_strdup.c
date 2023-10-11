/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:28:23 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/12 16:59:34 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*alt;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	alt = malloc(i * sizeof(char) + 1);
	if (!alt)
		return (0);
	while (j < i)
	{
		alt[j] = s1[j];
		j++;
	}
	alt[i] = '\0';
	return (alt);
}
