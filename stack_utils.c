/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:10:31 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/08 20:28:35 by gfrancoi         ###   ########.fr       */
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
	t_stack	*first;
	int		index;

	new = stack_new(value);
	if (!new)
		return (0);
	new->next = (*src);
	first = new;
	index = 0;
	while (new)
	{
		new->index = index;
		index++;
		new = new->next;
	}
	(*src) = first;
	return (1);
}

int	stack_pop(t_stack **src)
{
	t_stack	*top;
	t_stack	*first;
	int		index;

	top = *src;
	if (!top)
		return (0);
	*src = top->next;
	free(top);
	top = NULL;
	first = (*src);
	index = 0;
	while ((*src))
	{
		(*src)->index = index;
		index++;
		(*src) = (*src)->next;
	}
	(*src) = first;
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
