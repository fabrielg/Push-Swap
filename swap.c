/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:18:03 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/03 18:33:31 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sa(t_push_swap *ps)
{
	stack_swap(ps->a);
	ft_printf("sa\n");
}

void	sb(t_push_swap *ps)
{
	stack_swap(ps->b);
	ft_printf("sb\n");
}

void	ss(t_push_swap *ps)
{
	stack_swap(ps->a);
	stack_swap(ps->b);
	ft_printf("ss\n");
}
