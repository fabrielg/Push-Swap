/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:47:10 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/11 01:41:59 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_push_cost	find_target(t_stack *to_push, t_stack *b)
{
	t_push_cost	cost;
	t_stack		*b_temp;
	t_stack		*min;
	t_stack		*max;

	min = get_min(b);
	max = get_max(b);
	cost.stack = to_push;
	if (to_push->value < min->value || max->value < to_push->value)
		cost.target = max;
	else
	{
		b_temp = b;
		cost.target = NULL;
		while (b_temp->next && cost.target == NULL)
		{
			if ((b_temp->value > to_push->value)
				&& (to_push->value > b_temp->next->value))
				cost.target = b_temp->next;
			b_temp = b_temp->next;
		}
		if (!cost.target)
			cost.target = b;
	}
	return (cost);
}

static void	cost_a_calculation(size_t size_a, t_push_cost *target)
{
	size_t	nb_rotation;
	void	(*operation)(t_push_swap *);

	nb_rotation = target->stack->index;
	operation = &ra;
	if (target->stack->index > (int)(size_a / 2))
	{
		nb_rotation = size_a - target->stack->index;
		operation = &rra;
	}
	while (nb_rotation > 0)
	{
		ft_lstadd_back(&target->operations, ft_lstnew(operation));
		nb_rotation--;
	}
}

static void	cost_target_calculation(size_t size_b, t_push_cost *target)
{
	size_t	nb_rotation;
	void	(*operation)(t_push_swap *);

	nb_rotation = target->target->index;
	operation = &rb;
	if (target->target->index > (int)(size_b / 2))
	{
		nb_rotation = size_b - target->target->index;
		operation = &rrb;
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
	size_t	size_b;

	if (!a || !b || !target)
		return ;
	size_a = stack_size(a);
	size_b = stack_size(b);
	cost_a_calculation(size_a, target);
	cost_target_calculation(size_b, target);
	ft_lstadd_back(&target->operations, ft_lstnew(pb));
}

void	find_targets(t_push_swap *ps)
{
	t_stack	*a_temp;
	size_t	i;

	if (!ps->b || !ps->b->next)
		return ;
	if (ps->targets)
		ft_printf(NULL);	// Clear the targets
	ps->targets = ft_calloc(stack_size(ps->a) + 1, sizeof(t_push_cost));
	i = 0;
	a_temp = ps->a;
	while (a_temp)
	{
		(ps->targets)[i] = find_target(a_temp, ps->b);
		(ps->targets)[i].operations = NULL;
		find_operations(ps->a, ps->b, (ps->targets + i));
		i++;
		a_temp = a_temp->next;
	}
}
