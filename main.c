/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:48:06 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/12 16:20:29 by gfrancoi         ###   ########.fr       */
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
	}
	push_swap_clear(&ps);
	return (0);
}
