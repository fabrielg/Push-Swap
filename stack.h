/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:13:45 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/11 01:41:00 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# define UP 0
# define DOWN 1

typedef struct s_stack	t_stack;
typedef struct s_stack
{
	int		value;
	int		index;
	t_stack	*next;
}	t_stack;

int		stack_swap(t_stack *stk);
int		stack_push(t_stack **src, t_stack **dest);
void	stack_rotate(t_stack **stk, char direction);

t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *stk);
int		stack_add(t_stack **src, int value);
int		stack_pop(t_stack **src);
int		stack_clear(t_stack **stk);
void	stack_display(t_stack *stk);
void	stack_update(t_stack *stk);
size_t	stack_size(t_stack *stk);
t_stack	*get_min(t_stack *stk);
t_stack	*get_max(t_stack *stk);

#endif
