/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:20:49 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/22 21:11:22 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_in_b(t_push_swap *ps)
{
	t_list	*cheapest;
	void	(*operation)(t_push_swap *);
	size_t	nb_operations;
	size_t	i;

	find_targets_b(ps);
	cheapest = ps->targets->operations;
	nb_operations = ft_lstsize(cheapest);
	i = 1;
	while (i < ps->nb_targets && nb_operations > 1)
	{
		nb_operations = ft_lstsize((ps->targets + i)->operations);
		if (nb_operations < ft_lstsize(cheapest))
			cheapest = (ps->targets + i)->operations;
		i++;
	}
	while (cheapest)
	{
		operation = cheapest->content;
		(*operation)(ps);
		cheapest = cheapest->next;
	}
}

static void	sort_in_a(t_push_swap *ps)
{
	t_list	*operations_temp;
	void	(*operation)(t_push_swap *);

	while (ps->b)
	{
		find_target_a(ps);
		if (!ps->targets)
			return ;
		operations_temp = ps->targets->operations;
		while (operations_temp)
		{
			operation = operations_temp->content;
			(*operation)(ps);
			operations_temp = operations_temp->next;
		}
	}
}

static void	sort_three(t_push_swap *ps)
{
	t_stack	*min;

	if (stack_size(ps->a) != 3)
		return ;
	min = stack_get_min(ps->a);
	if (min->index == 0)
		ra(ps);
	else if (min->index == 1)
		rra(ps);
	if (ps->a->next->value < ps->a->value)
		sa(ps);
	rra(ps);
}

void	turk_sort(t_push_swap *ps)
{
	if (is_sorted(ps->a))
		return ;
	if (stack_size(ps->a) > 3)
	{
		pb(ps);
		if (stack_size(ps->a) > 3)
			pb(ps);
		while (stack_size(ps->a) > 3)
			sort_in_b(ps);
	}
	sort_three(ps);
	sort_in_a(ps);
	rotate_a_until_sorted(ps);
}
