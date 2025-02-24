/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:18:03 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 11:59:31 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *ps, int display)
{
	stack_swap(ps->a);
	if (display)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_push_swap *ps, int display)
{
	stack_swap(ps->b);
	if (display)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_push_swap *ps, int display)
{
	stack_swap(ps->a);
	stack_swap(ps->b);
	if (display)
		ft_putstr_fd("ss\n", 1);
}
