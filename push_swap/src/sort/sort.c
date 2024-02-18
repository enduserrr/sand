/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:18:24 by asalo             #+#    #+#             */
/*   Updated: 2024/02/18 12:55:14 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_n;

	cheapest_n = show_cheapest(*b);
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
	while ((*a)->value != smallest_value(*a)->value)
	{
		if (smallest_value(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	tiny_sort(t_stack_node **a, t_stack_node **b, bool is_5_elems)
{
	t_stack_node	*biggest_node;

	biggest_node = 0;
	if (is_5_elems)
	{
		biggest_node = largest_value(*a);
		if (biggest_node == *a)
			ra(a, false);
		else if ((*a)->next == biggest_node)
			rra(a, false);
		if ((*a)->value > (*a)->next->value)
			sa(a, false);
	}
	else
	{
		while (stack_len(*a) > 3)
		{
			init_nodes(*a, *b);
			min_to_top(a);
			pb(b, a, false);
		}
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	a_len;

	a_len = stack_len(*a);
	if (a_len == 5)
		tiny_sort(a, b, true);
	else
	{
		while (a_len-- > 3)
			move_a_to_b(a, b);
	}
	tiny_sort(a, b, false);
	while (*b)
	{
		init_nodes(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_to_top(a);
}
