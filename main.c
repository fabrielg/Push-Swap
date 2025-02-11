/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:48:06 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/11 22:53:24 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		pb(ps);
		pb(ps);
		ft_printf("A:\n");
		stack_display(ps->a);
		ft_printf("B:\n");
		stack_display(ps->b);
		ft_printf("\n");
		find_targets(ps);
		ft_printf("adress of sa: %p\n", sa);
		ft_printf("adress of sb: %p\n", sb);
		ft_printf("adress of ss: %p\n\n", ss);
		ft_printf("adress of pa: %p\n", pa);
		ft_printf("adress of pb: %p\n\n", pb);
		ft_printf("adress of ra: %p\n", ra);
		ft_printf("adress of rb: %p\n", rb);
		ft_printf("adress of rr: %p\n\n", rr);
		ft_printf("adress of rra: %p\n", rra);
		ft_printf("adress of rrb: %p\n", rrb);
		ft_printf("adress of rrr: %p\n", rrr);
		size_t	i = 0;
		t_push_cost	*targets = ps->targets;
		while (i < ps->nb_targets)
		{
			ft_printf("TARGET de %d: %d\n", (ps->targets + i)->stack->value, (ps->targets + i)->target->value);
			while ((ps->targets + i)->operations)
			{
				ft_printf("operation: %p\n", *(ps->targets + i)->operations);
				(ps->targets + i)->operations = (ps->targets + i)->operations->next;
			}
			ft_printf("\n");
			i++;
		}
	}
	push_swap_clear(&ps);
	return (0);
}
