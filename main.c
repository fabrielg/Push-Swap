/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:48:06 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/12 17:21:17 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_push_swap *ps)
{
	t_push_cost	*cheapest;
	void		(*operation)(t_push_swap *);
	size_t		nb_operations;
	size_t		i;

	find_targets(ps);
	cheapest = ps->targets;
	nb_operations = ft_lstsize(cheapest->operations);
	i = 1;
	while (i < ps->nb_targets && nb_operations > 1)
	{
		nb_operations = ft_lstsize((ps->targets + i)->operations);
		if (nb_operations < ft_lstsize(cheapest->operations))
			cheapest = (ps->targets + i);
		i++;
	}
	while (cheapest->operations)
	{
		operation = cheapest->operations->content;
		(*operation)(ps);
		cheapest->operations = cheapest->operations->next;
	}	
}

void	sort_three(t_push_swap *ps)
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
	pb(ps);
	pb(ps);
	ft_printf("A:\n");
	stack_display(ps->a);
	ft_printf("B:\n");
	stack_display(ps->b);
	ft_printf("\n");
	ft_printf("START SORTING:\n");
	while (stack_size(ps->a) > 3)
	{
		sort(ps);
		ft_printf("A:\n");
		stack_display(ps->a);
		ft_printf("B:\n");
		stack_display(ps->b);
		ft_printf("\n");
	}
	sort_three(ps);
	ft_printf("A:\n");
	stack_display(ps->a);
	ft_printf("B:\n");
	stack_display(ps->b);
	ft_printf("\n");
}

int	is_sorted(t_push_swap *ps)
{
	t_stack	*temp;
	int		prev_value;

	if (!ps || !ps->a)
		return (-1);
	temp = ps->a;
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

int	main(int ac, char **av)
{
	t_push_swap	*ps;
	t_stack		*a;

	if (ac <= 1)
		return (0);
	a = NULL;
	ps = NULL;
	if (!parsing(++av, &a))
		ft_printf("Error\n");
	else
	{
		init_push_swap(&ps, a);
		turk_sort(ps);
	}
	push_swap_clear(&ps);
	return (0);
}
