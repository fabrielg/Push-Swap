/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:48:06 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/23 12:54:48 by gfrancoi         ###   ########.fr       */
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
		ft_printf("I need operations here !\n");
	}
	push_swap_clear(&ps);
	return (0);
}
