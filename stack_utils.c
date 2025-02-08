/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:10:31 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/08 20:42:54 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}

int	stack_add(t_stack **src, int value)
{
	t_stack	*new;

	new = stack_new(value);
	if (!new)
		return (0);
	new->next = (*src);
	stack_update(new);
	(*src) = new;
	return (1);
}

int	stack_pop(t_stack **src)
{
	t_stack	*top;

	top = *src;
	if (!top)
		return (0);
	*src = top->next;
	stack_update((*src));
	free(top);
	top = NULL;
	return (1);
}

t_stack	*stack_last(t_stack *stk)
{
	t_stack	*last;

	last = stk;
	if (last)
	{
		while (last->next)
			last = last->next;
	}
	return (last);
}

int	stack_clear(t_stack **stk)
{
	if (!stk || !*stk)
		return (0);
	stack_clear(&(*stk)->next);
	free(*stk);
	*stk = NULL;
	return (1);
}
