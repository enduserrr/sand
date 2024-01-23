/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:03:30 by asalo             #+#    #+#             */
/*   Updated: 2024/01/23 19:14:35 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_ptr;

	if (!*src)
		return ;
	push_ptr = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_ptr->prev = NULL;
	if (!*dst)
	{
		*dst = push_ptr;
		push_ptr->next = NULL;
	}
	else
	{
		push_ptr->next = *dst;
		push_ptr->next->prev = push_ptr;
		*dst = push_ptr;
	}
}

/*Push the top of b to the top a*/
void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

/*Push the top of a to the top of b*/
void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
