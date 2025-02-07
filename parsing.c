/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:28:44 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/07 18:55:18 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_parsing(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	parsing(char **args, t_stack **stack)
{
	char	**split;
	int		value;
	size_t	i;

	while (*args)
	{
		split = ft_split((const char *)*args, ' ');
		if (!split)
			return (0);
		i = 0;
		while (split[i])
		{
			if (!ft_atoi_strict(split[i], &value))
			{
				free_parsing(split);
				return (0);
			}
			stack_add(stack, value);
			i++;
		}
		free_parsing(split);
		args++;
	}
	return (1);
}
