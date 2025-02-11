/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:32:08 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/11 13:56:32 by gfrancoi         ###   ########.fr       */
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
	int		cost;
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
void	find_targets(t_push_swap *ps);

void	sa(t_push_swap *ps);
void	sb(t_push_swap *ps);
void	ss(t_push_swap *ps);

void	pa(t_push_swap *ps);
void	pb(t_push_swap *ps);

void	ra(t_push_swap *ps);
void	rb(t_push_swap *ps);
void	rr(t_push_swap *ps);

void	rra(t_push_swap *ps);
void	rrb(t_push_swap *ps);
void	rrr(t_push_swap *ps);

int		parsing(char **args, t_stack **stack);

#endif
