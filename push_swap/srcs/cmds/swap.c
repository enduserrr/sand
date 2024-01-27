/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:16:20 by asalo             #+#    #+#             */
/*   Updated: 2024/01/24 14:39:01 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

static void	swap(t_stack_node **stack)
{
	if (!*stack || !(*stack)->next || stack_len(*stack) == 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node **a, bool checker)
{
	swap(a);
	if (!checker)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool checker)
{
	swap(b);
		if (!checker)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		ft_printf("ss\n");
}