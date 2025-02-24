/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:48:06 by gfrancoi          #+#    #+#             */
/*   Updated: 2025/02/24 11:50:31 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_entry
{
	char	*key;
	void	(*operation)(t_push_swap *, int display);
}	t_entry;

static void	*get_operation(char *operation)
{
	static t_entry	operations[] = {
		(t_entry){"pa\n", pa},
		(t_entry){"pb\n", pb},
		(t_entry){"ra\n", ra},
		(t_entry){"rb\n", rb},
		(t_entry){"rr\n", rr},
		(t_entry){"rra\n", rra},
		(t_entry){"rrb\n", rrb},
		(t_entry){"rrr\n", rrr},
		(t_entry){"sa\n", sa},
		(t_entry){"sb\n", sb},
		(t_entry){"ss\n", ss}
	};
	size_t			i;

	if (!operation)
		return (NULL);
	i = 0;
	while (i < 11)
	{
		if (!ft_strncmp(operation, operations[i].key, ft_strlen(operation)))
			return (operations[i].operation);
		i++;
	}
	return (NULL);
}

static void	execute(char *op, t_push_swap *ps)
{
	void	(*operation)(t_push_swap *, int display);

	operation = get_operation(op);
	if (!operation)
	{
		push_swap_clear(&ps);
		free(op);
		ft_putstr_fd("Error\n", 2);
		get_next_line(-42);
		exit(1);
	}
	operation(ps, 0);
}

static void	ask_operations(t_push_swap *ps)
{
	char		*op;

	op = get_next_line(0);
	while (op)
	{
		execute(op, ps);
		free(op);
		op = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_push_swap	*ps;
	t_stack		*a;

	if (ac <= 1)
		return (0);
	a = NULL;
	ps = NULL;
	if (!parsing(++av, &a))
		ft_putstr_fd("Error\n", 2);
	else
	{
		init_push_swap(&ps, a);
		if (!ps)
			ft_putstr_fd("Error\n", 2);
		else
		{
			ask_operations(ps);
			if (is_sorted(ps->a) && stack_size(ps->b) == 0)
				ft_putstr_fd("OK\n", 1);
			else
				ft_putstr_fd("KO\n", 1);
			get_next_line(-42);
		}
	}
	push_swap_clear(&ps);
	return (0);
}
