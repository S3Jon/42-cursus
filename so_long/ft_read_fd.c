/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:04:00 by jonsanch          #+#    #+#             */
/*   Updated: 2023/09/25 13:04:02 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
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
	//free((char *)s1);
	return (aux);
}
//No creo que
static char	*ft_strdup_gnl(const char *s1)
{
	char	*alt;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	alt = malloc((1 + i) * sizeof(char) + 1);
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

int	ft_read_fd(int fd, char **c)
{
	int		read_bits;
	char	*temp;

	read_bits = 1;
	while (read_bits > 0)
	{
		temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!temp)
			return (0);
		read_bits = read(fd, temp, BUFFER_SIZE);
		if (read_bits == -1)
		{
			free(temp);
			return (-1);
		}
		temp[read_bits] = '\0';
		if (*c == NULL)
			*c = ft_strdup_gnl(temp);
		else
			*c = ft_strjoin_gnl(*c, temp);
		free(temp);
	}
	return (0);
}
