/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:02:56 by asalo             #+#    #+#             */
/*   Updated: 2024/01/19 21:46:28 by asalo            ###   ########.fr       */
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

/*		ERROR HANDELING		*/
int		syntax_error(char *s);
int		duplicate_error(t_stack_node *a, int nbr);
void	free_stack(t_stack_node **stack);
void	error_free(t_stack_node **stack);

/*		INITIATE STACK		*/
void	current_index(t_stack_node *stack);
void	set_cheapest(t_stack_node *stack);
void	init_nodes_a(t_stack_node *a, t_stack_node *b);

/*		INITIATE NODES		*/


/*		STACK UTILS			*/
char	**ft_split(char const *s, char c);
int		stack_len(t_stack_node *stack);

/*		OPERATIONS			*/


/*		ALGORITHM			*/
#endif
