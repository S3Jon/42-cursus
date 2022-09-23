/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:18:36 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/20 16:05:18 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;
	t_list	*act;

	act = *lst;
	while (act != NULL)
	{
		nxt = act->next;
		del(act->content);
		free(act);
		act = nxt;
	}
	*lst = NULL;
}
