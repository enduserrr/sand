/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:10:32 by asalo             #+#    #+#             */
/*   Updated: 2024/02/15 10:55:42 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Function to find and append the last node to a linked list*/
static void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->n = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/*Function to define stack a and check for any errors and to append nodes needed*/
void	init_stack_a(t_stack_node **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	nbr = 0;
	i = 0;

	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag_argc_2)
		free_matrix(argv);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/*Function that moves the required node to the top of the stack*/
void	prep_for_push(t_stack_node **stack, t_stack_node *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (name == 'b')
		{
			if (top->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}