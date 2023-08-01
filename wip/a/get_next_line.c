#include "get_next_line.h"

static int ft_isthisline(char *c)
{
    size_t  a;

    a = 0;
    while (c[a] != '\0')
    {
        if (c[a] == '\n')
            return(a);
        a++;
    }
    return (-1);
}
 
static  void ft_getloan(int fd, char **c)
{
    int readbits;
    char *temp;
 
    readbits = 1;
    while (readbits > 0)
    {
        temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (!temp)
            return ;
        readbits = read(fd, temp, BUFFER_SIZE);
        if (readbits <= 0)
        {
            free(temp);
            return ;
        }
        temp[readbits] = '\0';
        if (*c == NULL)
            *c = ft_strdup(temp);
        else
            *c = ft_strjoin(*c, temp);
        free(temp);
        if (ft_isthisline(*c) != -1)
            return ;
    }
}
 
static char *ft_trimem(char **c)
{
    char *aux;
    char *retline;

    aux = ft_strdup(*c);
    free(*c);
    if (!aux)
        return (NULL);
    if (ft_isthisline(aux) == -1)
        return (aux);
    retline = ft_substr(aux, 0, (size_t)ft_isthisline(aux) + 1);
    *c = ft_substr(aux, (size_t)ft_isthisline(aux) + 1, (ft_strlen(aux) - (size_t)ft_isthisline(aux) + 1));
    free (aux);
    return (retline);
}
 
char* get_next_line(int fd)
{
    static char* bank;
 
    if ((fd < 0) || (BUFFER_SIZE <= 0))
        return (NULL);
    if (bank && ft_isthisline(bank) != -1)
        return(ft_trimem(&bank));
    ft_getloan(fd, &bank);
    if (!bank || bank == NULL)
        return (NULL);
    return (ft_trimem(&bank));    
}