/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:08:33 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/30 17:25:57 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	new->prev = NULL;
	return (new);
}

int	stack_push(t_stack **stk, int value)
{
	t_stack	*new;

	new = stack_new(value);
	if (new)
	{
		new->next = *stk;
		*stk = new;
		return (1);
	}
	return (0);
}

t_stack	*stack_pop(t_stack **stk)
{
	t_stack	*pop;

	pop = *stk;
	if (!pop)
		return (NULL);
	*stk = pop->next;
	pop->next = NULL;
	return (pop);
}
