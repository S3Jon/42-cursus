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

//lo intuitivo sería devolver una linea
//pero si opero sobre el pointer del str
//puedo agilizar el proceso

//leer v
static int	ft_rdline(int fd, char **cash)
{
	char	*act;
	char	*tot;
	int		bytes;

	test = malloc(sizeof(char) *(BUFFER_SIZE +1));
	if (!test)
		return (-1);
	while () //line no tenga un \n o \0
	{
		bytes = read(fd, act, BUFFER_SIZE); //tengo que añadir \0? idk
		if (bytes <= 0)
			break;
		tot = ft_strjoin(tot, act);  //igual enviar un int para saber si liberar memoria de los parametros enviados?
	}	
}

char	*get_next_line(int fd)
{
	static char	*bank;
	char		*cash;

	if (bank)
	{
		if (ft_gotline(bank) == 1)
			return (ft_reformat(&bank))
		cash = bank; // igual se ahorra esta + (n+1) linea con un free en el join
		free(bank);
	}
	else
		//leer;
	
	return (line);
}