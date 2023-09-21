/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:48:24 by jonsanch          #+#    #+#             */
/*   Updated: 2023/09/21 15:43:22 by jonsanch         ###   ########.fr       */
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
#  define BUFFER_SIZE 1024
# endif

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		ft_strnstr(const char *str, const char *to_find, size_t len);
char	**ft_map_create(int fd);
char	**ft_split(char const *s, char c);

typedef struct mapdata
{
	int		map_width;
	int		map_height;
	char	**map;
	int		collectible_count;
	int		start_count;
	int		exit_count;
}	t_mapdata;

#endif
