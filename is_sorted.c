/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:20:49 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/23 13:03:28 by gfrancoi         ###   ########.fr       */
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
