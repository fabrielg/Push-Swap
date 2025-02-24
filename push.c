/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:34:09 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 11:58:31 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_push_swap *ps, int display)
{
	stack_push(&(ps->b), &(ps->a));
	if (display)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_push_swap *ps, int display)
{
	stack_push(&(ps->a), &(ps->b));
	if (display)
		ft_putstr_fd("pb\n", 1);
}
