/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:48:06 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/07 19:45:57 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;

	if (ac <= 1)
		return (0);
	a = NULL;
	if (!parsing(++av, &a))
		ft_printf("Error\n");
	if (a)
		stack_clear(&a);
	return (0);
}
