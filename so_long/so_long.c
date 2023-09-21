/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:42:11 by jonsanch          #+#    #+#             */
/*   Updated: 2023/09/21 16:00:22 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//For testing purposes
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
//for testing purposes
int	main(int argc, char **argv)
{
	int	map_fd;

	map_fd = open(argv[1], O_RDONLY);
	if (argc != 2 || ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == 0
		|| map_fd == -1)
	{
		printf("Error\n");
		return (0);
	}

}
