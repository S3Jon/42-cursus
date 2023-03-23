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
	return (line);
}