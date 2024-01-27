/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:36:36 by asalo             #+#    #+#             */
/*   Updated: 2024/01/23 17:53:43 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

/*Function to return the len of stack in long*/
int	stack_len(t_stack_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

/*Function to return a pointer to the last node*/
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*Function to check if the stack is sorted in ascending order*/
bool	stack_asc_order(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*Function to return a pointer to the node with the smallest number*/
t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			min;
	t_stack_node	*node_ptr;

	min = LONG_MAX;
	node_ptr = NULL;
	while (stack)
	{
		if (stack->n < min)
		{
			min = stack->n;
			node_ptr = stack;
		}
		stack = stack->next;
	}
	return (node_ptr);
}

/*Function to return a pointer to the node with the largest number*/
t_stack_node	*find_largest(t_stack_node *stack)
{
	long			max;
	t_stack_node	*node_ptr;
	
	max = LONG_MIN;
	node_ptr = NULL;
	while (stack)
	{
		if (stack->n > max)
		{
			max = stack->n;
			node_ptr = stack;
		}
		stack = stack->next;
	}
	return (node_ptr);
}