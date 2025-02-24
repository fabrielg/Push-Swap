/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:32:07 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 11:28:45 by gfrancoi         ###   ########.fr       */
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
	if (!(*push_swap))
		return (0);
	(*push_swap)->a = stack_a;
	(*push_swap)->b = NULL;
	(*push_swap)->targets = NULL;
	(*push_swap)->nb_targets = 0;
	return (!!(*push_swap)->targets);
}

void	clear_targets(t_push_cost **targets, size_t nb_targets)
{
	size_t	i;

	if (!targets || !*targets)
		return ;
	i = 0;
	while (i < nb_targets)
	{
		if ((*targets + i)->operations)
			ft_lstclear(&((*targets + i)->operations), NULL);
		i++;
	}
	free(*targets);
	*targets = NULL;
}

void	push_swap_clear(t_push_swap **push_swap)
{
	if (!push_swap || !(*push_swap))
		return ;
	if ((*push_swap)->targets)
		clear_targets(&(*push_swap)->targets, (*push_swap)->nb_targets);
	if ((*push_swap)->a)
		stack_clear(&(*push_swap)->a);
	if ((*push_swap)->b)
		stack_clear(&(*push_swap)->b);
	free((*push_swap));
	push_swap = NULL;
}
