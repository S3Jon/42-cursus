/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:33:02 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/22 14:46:18 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrdcount(char const *s, char c)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	k = 0;
	l = 0;
	if (!s)
		return (0);
	while (s[j] != '\0')
	{
		l = 0;
		while (s[j] == c)
			j++;
		while (s[j + l] != c && s[j + l] != '\0')
			l++;
		if (l != 0)
			k++;
		j += l;
	}
	return (k);
}

static char	*ft_csubs(const char *s, size_t i, size_t j)
{
	char		*a;
	size_t		k;

	k = 0;
	a = (char *)malloc(j - i + 1);
	if (!a)
	{
		free(a);
		return (NULL);
	}
	while ((i + k) < j)
	{
		a[k] = s[i + k];
		k++;
	}
	a[k] = '\0';
	return (a);
}

char	**ft_killitall(char **a)
{
	size_t	c;

	c = 0;
	while (a[c])
	{
		free(a[c]);
		c++;
	}
	free(a);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	int			strc;
	char		**gigatemp;

	i = 0;
	strc = 0;
	gigatemp = (char **)malloc((sizeof(char *) * (ft_wrdcount(s, c) + 1)));
	if (!gigatemp || !s)
		return (NULL);
	while (s[i] != '\0' && strc < ft_wrdcount(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		gigatemp[strc] = ft_csubs(s, i, (j + i));
		if (gigatemp[strc] == NULL)
			return (ft_killitall(gigatemp));
		strc++;
		i += j;
	}
	gigatemp[strc] = 0;
	return (gigatemp);
}
