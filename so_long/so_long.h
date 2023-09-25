/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:48:24 by jonsanch          #+#    #+#             */
/*   Updated: 2023/09/25 13:12:10 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20000
# endif

size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	**ft_split(char *s, char c);
char	**ft_killitall(char **a);
int		ft_read_fd(int fd, char **c);
/* typedef struct mapdata
{
	int		map_width;
	int		map_height;
	char	**map;
	int		collectible_count;
	int		start_count;
	int		exit_count;
}	t_mapdata;
 */
#endif
