/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:34:09 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/03 18:35:46 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	pa(t_push_swap *ps)
{
	stack_push(&(ps->b), &(ps->a));
	ft_printf("pa\n");
}

void	pb(t_push_swap *ps)
{
	stack_push(&(ps->a), &(ps->b));
	ft_printf("pb\n");
}
