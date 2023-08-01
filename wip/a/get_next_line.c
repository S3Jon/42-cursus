#include "get_next_line.h"

static int ft_gotline(char *c)
{
    int i;

    i = 0;
    while (c[i] != '\0')
    {
        if (c[i] == '\n')
            return (i + 1);
        i++;
    }
    i = -1;
    return (i);
}

static  void ft_getloan(int fd, char **c)
{
    int readbits;
    char *temp;

    readbits = 1;
    temp = NULL;
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
       *c = ft_strjoin(*c, temp);
       if (ft_gotline(*c) != -1)
            return ;
    }
}

static char ft_trimem(char **c)
{
    char *aux;
    char *retline;

    aux = NULL;
    *aux = ft_strdrup(*c);
    retline = NULL;
    free(*c);
    if (ft_gotline(aux) == 1)
        retline = ft_substr(aux, 0, ft_strlen(aux));
    else
        retline = ft_substr(aux, 0, ft_gotline(aux));
    if (ft_gotline(aux) == ft_strlen(aux))
    {
        free(aux);
        return (*retline);
    }
    c = ft_substr(aux, ft_gotline(aux) + 1, ft_strlen(aux));
    free(aux);
    return (*retline);
}

char* get_next_line(int fd)
{
    static char* bank;

    if ((fd < 0) || (BUFFER_SIZE <= 0))
        return (0);
    if (bank && ft_gotline(bank) != -1)
        return(*ft_trimem(&bank));
    ft_getloan(fd, &bank);
    if (!bank);
        return (0);
    return (*ft_trimem(&bank));    
}