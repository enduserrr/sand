/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:19:26 by asalo             #+#    #+#             */
/*   Updated: 2024/02/17 14:54:30 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_to_top(t_stack_node **a)
{
	while ((*a)->n != find_min(*a)->n)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	tiny_sort(t_stack_node **a, t_stack_node **b, int checker)
{
	t_stack_node	*biggest_node;

	biggest_node = 0;
	if (checker == 3)
	{
		biggest_node = find_max(*a);
		if (biggest_node == *a) //Check if the current node is the biggest
			ra(a, false); //If so, rotate the top node to the bottom of the stack
		else if ((*a)->next == biggest_node) //Check if the second node is the biggest
			rra(a, false); //If so, reverse rotate the bottom node, to the top of the stack
		if ((*a)->n > (*a)->next->n) //Check if the bottom node is the biggest, but the top node is higher than the second node
			sa(a, false); //If so, simply swap the top and second nodes
	}
	else if (checker == 5)
	{
		while (stack_len(*a) > 3)
		{
			init_nodes_a(*a, *b);
			min_to_top(a);
			pb(b, a, false);
		}
	}
}
