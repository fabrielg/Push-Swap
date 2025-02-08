/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:10:31 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/08 20:40:09 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_update(t_stack *stk)
{
	int	index;

	index = 0;
	while (stk)
	{
		stk->index = index;
		index++;
		stk = stk->next;
	}
}
