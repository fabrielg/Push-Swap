/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:20:49 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 11:38:17 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_in_b(t_push_swap *ps)
{
	t_list	*cheapest;
	void	(*operation)(t_push_swap *, int display);
	size_t	nb_operations;
	size_t	i;

	if (!find_targets_b(ps))
		return ;
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
		(*operation)(ps, 1);
		cheapest = cheapest->next;
	}
}

static void	sort_in_a(t_push_swap *ps)
{
	t_list	*operations_temp;
	void	(*operation)(t_push_swap *, int display);

	while (ps->b)
	{
		if (!find_target_a(ps))
			return ;
		operations_temp = ps->targets->operations;
		while (operations_temp)
		{
			operation = operations_temp->content;
			(*operation)(ps, 1);
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
		ra(ps, 1);
	else if (min->index == 1)
		rra(ps, 1);
	if (ps->a->next->value < ps->a->value)
		sa(ps, 1);
	rra(ps, 1);
}

void	rotate_a_until_sorted(t_push_swap *ps)
{
	t_stack	*min;
	size_t	size_a;
	void	(*operation)(t_push_swap *, int display);

	min = stack_get_min(ps->a);
	size_a = stack_size(ps->a);
	operation = &ra;
	if (min->index > (int)(size_a / 2))
		operation = &rra;
	while (!is_sorted(ps->a))
		(*operation)(ps, 1);
}

int	turk_sort(t_push_swap *ps)
{
	if (!ps)
		return (0);
	if (is_sorted(ps->a))
		return (1);
	if (stack_size(ps->a) > 3)
	{
		pb(ps, 1);
		if (stack_size(ps->a) > 3)
			pb(ps, 1);
		while (stack_size(ps->a) > 3)
			sort_in_b(ps);
	}
	sort_three(ps);
	sort_in_a(ps);
	rotate_a_until_sorted(ps);
	return (1);
}
