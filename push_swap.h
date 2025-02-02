/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:32:08 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/03 00:29:18 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

# ifndef UP
#  define UP 0
# endif

# ifndef DOWN
#  define DOWN 1
# endif

typedef struct s_stack	t_stack;
typedef struct s_stack
{
	int		value;
	t_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	int				value;
	unsigned int	cost;
}	t_push_swap;

int		stack_swap(t_stack *stk);
int		stack_push(t_stack **src, t_stack **dest);
void	stack_rotate(t_stack **stk, char direction);

t_stack	*stack_new(int value);
void	stack_add(t_stack **src, int value);
t_stack	*stack_last(t_stack *stk);
void	stack_display(t_stack *stk);

#endif
