/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:48:06 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/03 19:43:29 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = ft_calloc(sizeof(t_stack), 1);
	b = NULL;
	for (int i = 1; i <= 25; i++)
		stack_add(&a, i);

	t_push_swap	*ps;

	ps = ft_calloc(sizeof(t_push_swap), 1);
	if (!ps)
		return (1);
	ps->a = a;
	ps->b = b;

	sa(ps);
	sb(ps);
	ss(ps);

	pa(ps);
	pb(ps);

	sa(ps);
	sb(ps);
	ra(ps);
	sb(ps);
	ss(ps);

	pa(ps);
	pb(ps);
	sb(ps);
	ss(ps);
	ss(ps);

	pa(ps);
	pb(ps);
	sa(ps);
	sb(ps);
	sb(ps);
	ss(ps);

	pa(ps);
	pb(ps);
	sb(ps);
	ra(ps);
	rb(ps);
	rr(ps);

	sb(ps);
	ra(ps);
	rra(ps);
	rrb(ps);
	sb(ps);
	ss(ps);

	pa(ps);
	pb(ps);

	pa(ps);
	pb(ps);
	sb(ps);
	ss(ps);

	pa(ps);
	pb(ps);
	sa(ps);
	sb(ps);
	sb(ps);
	ss(ps);

	pa(ps);
	pb(ps);
	sb(ps);
	ra(ps);
	rb(ps);
	rr(ps);

	sb(ps);
	ra(ps);
	rra(ps);
	rrb(ps);
	sa(ps);
	stack_display(ps->a);
	// ft_printf("\n\n");
	// stack_display(ps->b);
	//sb(ps);
	//rrr(ps);
	free(ps);
	return (0);
}
