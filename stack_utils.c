/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:10:31 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/03 17:50:42 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->value = value;
	return (new);
}

void	stack_add(t_stack **src, int value)
{
	t_stack	*new;

	new = stack_new(value);
	if (!new)
		return ;
	new->next = (*src);
	(*src) = new;
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

void	stack_display(t_stack *stk)
{
	while (stk)
	{
		printf("- %03d -\n", stk->value);
		stk = stk->next;
	}
}
