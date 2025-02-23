/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:36:01 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/23 13:39:46 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->a), UP);
	if (display)
		ft_printf("ra\n");
}

void	rb(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->b), UP);
	if (display)
		ft_printf("rb\n");
}

void	rr(t_push_swap *ps, int display)
{
	stack_rotate(&(ps->a), UP);
	stack_rotate(&(ps->b), UP);
	if (display)
		ft_printf("rr\n");
}
