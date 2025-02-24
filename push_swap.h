/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:32:08 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 11:30:17 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "./libft/libft.h"
# include "stack.h"

typedef struct s_push_cost
{
	t_stack	*stack;
	t_stack	*target;
	t_list	*operations;
}	t_push_cost;

typedef struct s_push_swap
{
	t_stack		*a;
	t_stack		*b;
	t_push_cost	*targets;
	size_t		nb_targets;
}	t_push_swap;

int		init_push_swap(t_push_swap **push_swap, t_stack *stack_a);
void	push_swap_clear(t_push_swap **push_swap);
void	clear_targets(t_push_cost **targets, size_t nb_targets);
int		find_targets_b(t_push_swap *ps);
int		find_target_a(t_push_swap *ps);
void	operations_optimizer(t_list **operations);
int		turk_sort(t_push_swap *ps);
void	rotate_a_until_sorted(t_push_swap *ps);
int		is_sorted(t_stack *stack);

void	sa(t_push_swap *ps, int display);
void	sb(t_push_swap *ps, int display);
void	ss(t_push_swap *ps, int display);

void	pa(t_push_swap *ps, int display);
void	pb(t_push_swap *ps, int display);

void	ra(t_push_swap *ps, int display);
void	rb(t_push_swap *ps, int display);
void	rr(t_push_swap *ps, int display);

void	rra(t_push_swap *ps, int display);
void	rrb(t_push_swap *ps, int display);
void	rrr(t_push_swap *ps, int display);

int		parsing(char **args, t_stack **stack);

#endif
