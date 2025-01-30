/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:32:07 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/01/30 17:12:07 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stk)
{
	t_stack	*temp;

	if (!stk || !stk->next)
		return ;
	temp = stk;
	stk = stk->next;
	stk->next = temp;
}

void	push(t_stack *stk_from, t_stack *stk_to)
{
	t_stack	*temp;

	if (!stk_from)
		return ;
	temp = stk_from->next;
	stk_from->next = stk_to;
	stk_to = stk_from;
	stk_from = temp;
}

void	rotate(t_stack *stk)
{
	
}

void	reverse_rotate(t_stack *stk)
{

}
