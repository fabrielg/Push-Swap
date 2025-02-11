/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:45:00 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/12 00:12:27 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*get_double_operation(void *a, void *b)
{
	if ((a == sa && b == sb) || (a == sb && b == sa))
		return (ss);
	else if ((a == ra && b == rb) || (a == rb && b == ra))
		return (rr);
	else if ((a == rra && b == rrb) || (a == rrb && b == rra))
		return (rrr);
	return (NULL);
}

static void	add_n_operation(t_list **lst, int n, void *operation)
{
	while (n > 0)
	{
		ft_lstadd_back(lst, ft_lstnew(operation));
		n--;
	}
}

static void	compare(t_list **new, t_list *operations, void *first, void *second)
{
	int	nb_first;
	int	nb_second;

	nb_first = ft_lstnb_find(operations, first);
	nb_second = ft_lstnb_find(operations, second);
	if (nb_first == 0 || nb_second == 0)
	{
		add_n_operation(new, nb_first, first);
		add_n_operation(new, nb_second, second);
		return ;
	}
	if (nb_first >= nb_second && get_double_operation(first, second))
	{
		add_n_operation(new, nb_second, get_double_operation(first, second));
		add_n_operation(new, nb_first - nb_second, first);
	}
	else if (get_double_operation(first, second))
	{
		add_n_operation(new, nb_first, get_double_operation(first, second));
		add_n_operation(new, nb_second - nb_first, second);
	}
}

void	operations_optimizer(t_list **operations)
{
	t_list	*optimized;
	t_list	*temp;

	optimized = NULL;
	compare(&optimized, *operations, sa, sb);
	compare(&optimized, *operations, ra, rb);
	compare(&optimized, *operations, rra, rrb);
	temp = optimized;
	while ((*operations))
	{
		if ((*operations)->content == pa || (*operations)->content == pb)
			add_n_operation(&optimized, 1, (*operations)->content);
		(*operations) = (*operations)->next;
	}
	ft_lstclear(operations, NULL);
	(*operations) = temp;
}
