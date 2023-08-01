#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024;
# endif

char    *ft_strdup(const char *s1);
size_t ft_strlen(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, size_t start, size_t len);
char *get_next_line(int fd);

#endif