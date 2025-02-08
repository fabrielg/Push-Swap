/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:28:44 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/09 00:53:59 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	apply_parsing(char **strs, t_stack **stack)
{
	size_t	i;
	int		value;

	i = 0;
	while (strs[i])
	{
		if (!ft_atoi_strict(strs[i], &value))
		{
			free_split(strs);
			stack_clear(stack);
			return (0);
		}
		stack_add(stack, value);
		i++;
	}
	return (1);
}

static int	has_duplicates(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (temp->value == stack->value)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	parsing(char **args, t_stack **dest)
{
	char	**split;
	t_stack	*temp;
	t_stack	*temp_temp;

	temp = NULL;
	while (*args)
	{
		split = ft_split((const char *)*args, ' ');
		if (!split)
			return (stack_clear(&temp), 0);
		if (!apply_parsing(split, &temp))
			return (0);
		free_split(split);
		args++;
	}
	temp_temp = temp;
	while (temp)
	{
		stack_add(dest, temp->value);
		temp = temp->next;
	}
	stack_clear(&temp_temp);
	if (has_duplicates(*dest))
		return (stack_clear(dest), 0);
	return (1);
}
