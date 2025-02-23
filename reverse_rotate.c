/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:37:12 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/23 13:40:05 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->a), DOWN);
	if (display)
		ft_printf("rra\n");
}

void	rrb(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->b), DOWN);
	if (display)
		ft_printf("rrb\n");
}

void	rrr(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->a), DOWN);
	stack_rotate(&(ps->b), DOWN);
	if (display)
		ft_printf("rrr\n");
}
