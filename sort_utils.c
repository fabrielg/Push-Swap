/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:20:49 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/22 13:56:35 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;
	int		prev_value;

	if (!stack)
		return (-1);
	temp = stack;
	prev_value = temp->value;
	while (temp->next)
	{
		if (prev_value > temp->next->value)
			return (0);
		temp = temp->next;
		prev_value = temp->value;
	}
	return (1);
}

void	rotate_a_until_sorted(t_push_swap *ps)
{
	t_stack	*min;
	size_t	size_a;
	void	(*operation)(t_push_swap *);

	min = stack_get_min(ps->a);
	size_a = stack_size(ps->a);
	operation = &ra;
	if (min->index > (int)(size_a / 2))
		operation = &rra;
	while (!is_sorted(ps->a))
		(*operation)(ps);
}
