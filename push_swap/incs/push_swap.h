/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:02:56 by asalo             #+#    #+#             */
/*   Updated: 2024/01/27 18:14:52 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/incs/libft.h"/**/
# include "libft/incs/ft_printf.h"/*to print outputs*/
# include <stdbool.h>/*to use boolean datat type*/
# include <limits.h>/*to define MIN & MAX macros*/

typedef struct s_stack_node
{
	int					n;/*current number*/
	int					index;/*the numbers location on the stack*/
	int					push_cost;/*actions n to push n to correct positon in B*/
	bool				above_median;/*to calculate cost, tells if RA or RRA*/
	bool				cheapest;/*the node that is the cheapest PA*/
	struct s_stack_node	*target_node;/*target node for n in the opposite stack*/
	struct s_stack_node	*next;/*pointer to the next node*/
	struct s_stack_node	*prev;/*pointer to the prev node*/
}	t_stack_node;

/*		ERROR & FREE		*/
int				syntax_error(char *s);
int				duplicate_error(t_stack_node *a, int nbr);
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **stack);

/*		INITIATE STACK		*/
void			init_stack_a(t_stack_node **a, char **argv);
char			**split(char *s, char c);

/*		INITIATE NODES		*/
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top, char name);
t_stack_node	*get_cheapest(t_stack_node *stack);

/*		 STACK UTILS		*/
int				stack_len(t_stack_node *stack);
bool			stack_asc_order(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*find_largest(t_stack_node *stack);

/*		ALGORITHM			*/
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);

/*		COMMANDS			*/
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);

#endif
