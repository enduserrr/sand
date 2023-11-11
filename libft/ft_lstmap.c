/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:05:26 by asalo             #+#    #+#             */
/*   Updated: 2023/11/11 15:59:22 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!f || !lst)
		return (0);
	new = 0;
	while (lst != 0)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&node, (*del));
			return (0);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}