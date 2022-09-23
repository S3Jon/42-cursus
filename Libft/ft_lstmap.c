/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:46:51 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/22 18:33:47 by jonsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*nxt;
	void	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst->content);
	curr = ft_lstnew(tmp);
	if (!curr)
		del(tmp);
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		nxt = ft_lstnew(tmp);
		if (!nxt)
		{
			del(tmp);
			ft_lstclear(&curr, del);
			return (NULL);
		}
		ft_lstadd_back(&curr, nxt);
		lst = lst->next;
	}
	return (curr);
}
