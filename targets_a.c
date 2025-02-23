/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:47:10 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/23 13:42:37 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target(t_stack *to_push, t_stack *a, t_push_cost *target)
{
	t_stack		*a_temp;
	t_stack		*min;
	t_stack		*max;

	min = stack_get_min(a);
	max = stack_get_max(a);
	target->stack = to_push;
	if (to_push->value < min->value || max->value < to_push->value)
		target->target = min;
	else
	{
		a_temp = a;
		target->target = NULL;
		while (a_temp->next && target->target == NULL)
		{
			if ((a_temp->value < to_push->value)
				&& (to_push->value < a_temp->next->value))
				target->target = a_temp->next;
			a_temp = a_temp->next;
		}
		if (!target->target)
			target->target = a;
	}
}

static void	cost_a_calculation(size_t size_a, t_push_cost *target)
{
	size_t	nb_rotation;
	void	(*operation)(t_push_swap *, int display);

	nb_rotation = target->target->index;
	operation = &ra;
	if (target->target->index > (int)(size_a / 2))
	{
		nb_rotation = size_a - target->target->index;
		operation = &rra;
	}
	while (nb_rotation > 0)
	{
		ft_lstadd_back(&target->operations, ft_lstnew(operation));
		nb_rotation--;
	}
}

static void	find_operations(t_stack *a, t_stack *b, t_push_cost *target)
{
	size_t	size_a;

	if (!a || !b || !target)
		return ;
	size_a = stack_size(a);
	target->operations = NULL;
	cost_a_calculation(size_a, target);
	ft_lstadd_back(&target->operations, ft_lstnew(pa));
}

void	find_target_a(t_push_swap *ps)
{
	t_stack	*current;

	if (!ps || !ps->a || !ps->b)
		return ;
	if (ps->targets)
		clear_targets(&ps->targets, ps->nb_targets);
	ps->nb_targets = 1;
	ps->targets = ft_calloc(ps->nb_targets, sizeof(t_push_cost));
	current = ps->b;
	find_target(current, ps->a, ps->targets);
	find_operations(ps->a, ps->b, ps->targets);
}
