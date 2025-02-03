/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:13:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/03 18:14:40 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

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

int		stack_swap(t_stack *stk);
int		stack_push(t_stack **src, t_stack **dest);
void	stack_rotate(t_stack **stk, char direction);

t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stk);
void	stack_add(t_stack **src, int value);
void	stack_display(t_stack *stk);

#endif
