/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:36:36 by asalo             #+#    #+#             */
/*   Updated: 2024/02/17 15:48:59 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*smallest_value(t_stack_node *stack)
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
/*
 * When i have 3 nodes, easy to sort
 * 	~If the 1* is the biggest, ra (biggestto bottom)
 * 	~If the 2* is the biggest, rra (biggest to bottom)
 * 	~Now i have forcefully the Biggest at the bottom
 * 		so i just chek 1° and 2°
*/
t_stack_node	*largest_value(t_stack_node *stack)
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