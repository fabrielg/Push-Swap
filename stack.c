/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:08:33 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/03 00:45:55 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_swap(t_stack *stk)
{
	int	temp;

	if (!stk || !stk->next)
		return (0);
	temp = stk->value;
	stk->value = stk->next->value;
	stk->next->value = temp;
	return (1);
}

int	stack_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!(*src))
		return (0);
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
	return (1);
}

static void	stack_rotate_up(t_stack **stk)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*stk)->next)
		return ;
	temp = *stk;
	*stk = (*stk)->next;
	last = stack_last(*stk);
	temp->next = NULL;
	last->next = temp;
}

static void	stack_rotate_down(t_stack **stk)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*second_last;

	last = stack_last(*stk);
	second_last = (*stk);
	if (second_last && second_last->next)
	{
		while (second_last->next->next)
			second_last = second_last->next;
	}
	temp = *stk;
	*stk = last;
	(*stk)->next = temp;
	second_last->next = NULL;
}

void	stack_rotate(t_stack **stk, char direction)
{
	if (!stk || !(*stk))
		return ;
	if (direction == UP)
		stack_rotate_up(stk);
	else if (direction == DOWN)
		stack_rotate_down(stk);
}
