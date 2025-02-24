/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:37:12 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 11:58:52 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->a), DOWN);
	if (display)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->b), DOWN);
	if (display)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->a), DOWN);
	stack_rotate(&(ps->b), DOWN);
	if (display)
		ft_putstr_fd("rrr\n", 1);
}
