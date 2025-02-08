/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:32:07 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/09 00:52:04 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_push_swap(t_push_swap **push_swap, t_stack *stack_a)
{
	t_stack	*last;

	last = stack_last(stack_a);
	if (!last)
		return (0);
	(*push_swap) = ft_calloc(1, sizeof(t_push_swap));
	if (!push_swap)
		return (0);
	(*push_swap)->a = stack_a;
	(*push_swap)->b = NULL;
	(*push_swap)->targets = ft_calloc(last->index + 2, sizeof(t_push_cost));
	return (!!(*push_swap)->targets);
}

void	push_swap_clear(t_push_swap **push_swap)
{
	if (!push_swap || !(*push_swap))
		return ;
	if ((*push_swap)->a)
		stack_clear(&(*push_swap)->a);
	if ((*push_swap)->b)
		stack_clear(&(*push_swap)->a);
	if ((*push_swap)->targets)
	{
		if ((*push_swap)->targets->stack)
			stack_clear(&(*push_swap)->targets->stack);
		free((*push_swap)->targets);
	}
	free((*push_swap));
	push_swap = NULL;
}
