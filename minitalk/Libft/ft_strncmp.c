/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:58:04 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/19 09:41:59 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	while (((s1[k] != '\0') || (s2[k] != '\0')) && (k < n))
	{
		if (s1[k] != s2[k])
			return ((unsigned char)s1[k] - (unsigned char)s2[k]);
		k++;
	}
	return (0);
}
