/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:18:24 by asalo             #+#    #+#             */
/*   Updated: 2024/01/27 20:29:08 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	rotate_both(t_stack_node **a, t_stack_node **b,
// 						t_stack_node *cheapest_n)
// {
// 	while (*b != cheapest_n->target_node && *a != cheapest_n)
// 		rr(a, b, false);
// 		current_index(*a);
// 		current_index(*b);
// }

// static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
// 						t_stack_node *cheapest_n)
// {
// 	while (*b != cheapest_n->target_node && *a != cheapest_n)
// 		rrr(a, b, false);
// 		current_index(*a);
// 		current_index(*b);
// }

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_n;

	cheapest_n = get_cheapest(*b);
	if (cheapest_n->above_median && cheapest_n ->target_node->above_median)
	{
		while (*b != cheapest_n->target_node && *a != cheapest_n)
		{
			rr(a, b, false);
			current_index(*a);
			current_index(*b);
		}
	}
	else if (!(cheapest_n->above_median) && !(cheapest_n->target_node->above_median))
	{
		while (*b != cheapest_n->target_node && *a != cheapest_n)
		{
			rrr(a, b, false);
			current_index(*a);
			current_index(*b);
		}
	}
	prep_for_push(a, cheapest_n, 'a');
	prep_for_push(b, cheapest_n, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

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

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	a_len;

	a_len = stack_len(*a);
	if(a_len-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (a_len-- > 3 && !stack_sorted(*a))
		pb(b, a, false);;
	while (a_len-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b) //Until the end of stack `b` is reached
	{
		init_nodes_b(*a, *b); //Initiate all nodes from both stacks
		move_b_to_a(a, b); //Move all `b` nodes back to a sorted stack `a`
	}
	current_index(*a);
	min_to_top(a);
}