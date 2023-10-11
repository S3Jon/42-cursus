/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:49:10 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/22 14:46:38 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != 0 && i < j)
		i++;
	while (ft_strchr(set, s1[j]) != 0 && j > i)
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}
