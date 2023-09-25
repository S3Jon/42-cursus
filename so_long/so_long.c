/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:42:11 by jonsanch          #+#    #+#             */
/*   Updated: 2023/09/25 13:16:25 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//For testing purposes
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
//for testing purposes

void	ft_clear_map(char *singleline_map)
{
	free(singleline_map);
	singleline_map = NULL;
}

int	ft_readymap(int	fd)
{
	char	*singleline_map;
	char	**ms_map;

	singleline_map = NULL;
	ms_map = NULL;
	if (ft_read_fd(fd, &singleline_map) == -1)
	{
		free(singleline_map);
		singleline_map = NULL;
		return (-1);
	}
	printf("\n");
	printf("\n%s\n", singleline_map);
	ms_map = ft_split(singleline_map, '\n');
	ft_clear_map(singleline_map);
	if (!ms_map)
	{
		printf("///ERROR IN SPLIT///");
		return (-1);
	}
	int	i = 0;
	printf("\n---Splitted map---\n");
	while (ms_map[i] != NULL)
		printf("%s\n", ms_map[i++]);
	ft_killitall(ms_map); //for testing purposes
	return (0);
}

int	main(int argc, char **argv)
{
	int	map_fd;
	int	temp;

	map_fd = open(argv[1], O_RDONLY);
	if (argc != 2 || ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0
		|| map_fd == -1)
		printf("Error\n");
	else
	{
		printf("Succ");
		temp = ft_readymap(map_fd);
		printf("\n%d\n", temp);
	}
	return (0);
}
