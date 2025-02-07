/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:10:31 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/07 14:51:50 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_display(t_stack *stk)
{
	while (stk)
	{
		ft_printf("- %03d -\n", stk->value);
		stk = stk->next;
	}
}
