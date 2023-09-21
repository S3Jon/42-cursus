/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:55:03 by jonsanch          #+#    #+#             */
/*   Updated: 2023/09/21 15:44:23 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_singleline_map(int fd)
{
	char	*old;
	char	*mix;
	char	*new;
	size_t	i;

	i = 1;
	new = NULL;
	old = NULL;
	while (i != 0)
	{
		new = get_next_line(fd);
		mix = ft_strjoin(old, new);
		i = ft_strlen(new);
		free(old);
		free(new);
		old = mix;
		free(mix);
	}
	return (old);
}

char	**ft_map_create(int fd)
{
	char	**map;
	char	*one_line_map;

	map = NULL;
	one_line_map = NULL;
	one_line_map = ft_singleline_map(fd);
	map = ft_split(one_line_map, '\n');
	return (map);
}