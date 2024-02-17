/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:19:26 by asalo             #+#    #+#             */
/*   Updated: 2024/02/15 12:42:46 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*A sort function for when a has three nodes*/
void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a) //Check if the current node is the biggest
		ra(a, false); //If so, rotate the top node to the bottom of the stack
	else if ((*a)->next == biggest_node) //Check if the second node is the biggest
		rra(a, false); //If so, reverse rotate the bottom node, to the top of the stack
	if ((*a)->n > (*a)->next->n) //Check if the bottom node is the biggest, but the top node is higher than the second node
		sa(a, false); //If so, simply swap the top and second nodes
}