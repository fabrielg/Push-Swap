/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:48:06 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 11:58:06 by gfrancoi         ###   ########.fr       */
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
		ft_putstr_fd("Error\n", 2);
	else
	{
		init_push_swap(&ps, a);
		if (!turk_sort(ps))
			ft_putstr_fd("Error\n", 2);
	}
	push_swap_clear(&ps);
	return (0);
}
