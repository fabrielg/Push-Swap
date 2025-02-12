/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_min_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 01:39:40 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/11 01:41:45 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_min(t_stack *stk)
{
	t_stack	*min;

	if (!stk)
		return (NULL);
	min = stk;
	while (stk)
	{
		if (min->value > stk->value)
			min = stk;
		stk = stk->next;
	}
	return (min);
}

t_stack	*get_max(t_stack *stk)
{
	t_stack	*max;

	if (!stk)
		return (NULL);
	max = stk;
	while (stk)
	{
		if (max->value < stk->value)
			max = stk;
		stk = stk->next;
	}
	return (max);
}
