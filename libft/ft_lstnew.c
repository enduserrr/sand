/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:58:25 by asalo             #+#    #+#             */
/*   Updated: 2023/11/09 14:10:36 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
}
/*int main()
{
	char content[20] = "CONTENT.";
	t_list *result = ft_lstnew((void *)content, 16);
	printf("The content is %s", (char *)result->content);
	printf("The content size is %zu", result->content_size);
:	return (0);
}*/