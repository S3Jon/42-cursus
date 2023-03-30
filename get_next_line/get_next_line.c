/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 02:30:28 by jonsanch          #+#    #+#             */
/*   Updated: 2022/10/13 02:30:28 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GET_NEXT_LINE.H"
//lo intuitivo sería devolver una linea
//pero si opero sobre el pointer del str
//puedo agilizar el proceso

//leer v

static int	ft_gotline(char *c)
{
	while (*c != '\0')
	{
		if (*c == '\n')
			return (1);
		*c++;
	}
	return (0);
}
static int	ft_rdline(int fd, char **cash)
{
	char	*act;
	char	*tot;
	int		rdbytes;

	act = malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!act)
		return (-1);
	while (ft_gotline(tot) == 0) //line no tenga un \n o \0 ed2: igual añadir que lea mientras read != 0?
	{
		rdbytes = read(fd, act, BUFFER_SIZE); //tengo que añadir \0? idk
		if (rdbytes <= 0)
			break;
		tot = ft_strjoin(tot, act);  //igual enviar un int para saber si liberar memoria de los parametros enviados?
	}
	free(act);
	return (rdbytes);
}

char	*get_next_line(int fd)
{
	static char	*bank;
	char		*cash;

	if (bank)
	{
		if (ft_gotline(bank) == 1)
			return (ft_reformat(&bank));
		cash = bank; // igual se ahorra esta + (n+1) linea con un free en el join
		free(bank);
	}
	else
		//leer;
	
	return (line);
}