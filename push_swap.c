/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:32:07 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/11 00:40:19 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_push_swap(t_push_swap **push_swap, t_stack *stack_a)
{
	size_t	nb_element;

	nb_element = stack_size(stack_a);
	if (nb_element == 0)
		return (0);
	(*push_swap) = ft_calloc(1, sizeof(t_push_swap));
	if (!push_swap)
		return (0);
	(*push_swap)->a = stack_a;
	(*push_swap)->b = NULL;
	(*push_swap)->targets = NULL;
	return (!!(*push_swap)->targets);
}

void	push_swap_clear(t_push_swap **push_swap)
{
	if (!push_swap || !(*push_swap))
		return ;
	if ((*push_swap)->a)
		stack_clear(&(*push_swap)->a);
	if ((*push_swap)->b)
		stack_clear(&(*push_swap)->b);
	/*if ((*push_swap)->targets)
	{
		if ((*push_swap)->targets->stack)
			stack_clear(&(*push_swap)->targets->stack);
		free((*push_swap)->targets);
	}*/
	free((*push_swap));
	push_swap = NULL;
}
