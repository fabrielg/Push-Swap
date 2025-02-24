/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:36:01 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 11:59:08 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->a), UP);
	if (display)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->b), UP);
	if (display)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->a), UP);
	stack_rotate(&(ps->b), UP);
	if (display)
		ft_putstr_fd("rr\n", 1);
}
