/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:27:07 by asalo             #+#    #+#             */
/*   Updated: 2024/01/19 20:13:09 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

int	syntax_error(char *s)
{
	if (!(s[0] == '+' || s[0] == '-' || (s[0] >= '0' && s[0] <= '9')))
		return (1);
	if ((s[0] == '+' || s[0] == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (*++s)
	{
		if (!(s[0] >= '0' && s[0] <= '9'))
			return (1);
	}
	return (0);
}

int	duplicate_error(t_stack_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->n == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}
