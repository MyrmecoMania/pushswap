/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:14:11 by enorie            #+#    #+#             */
/*   Updated: 2024/01/06 13:07:25 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse(int i, char **argv, t_list **stack_a)
{
	int		size;
	t_list	*new;

	size = ft_tabsize(argv) - 1;
	while (i <= size)
	{
		if (!(ft_atoi_long(argv[size]) > 2147483647)
			&& !(ft_atoi_long(argv[size]) < -2147483648)
			&& !(ft_check_nbr(argv[size]))
			&& !(ft_uniq(*stack_a, ft_atoi_long(argv[size]))))
		{
			new = ft_lstnew((int)ft_atoi_long(argv[size]));
			if (!new)
				return (ft_puterror(stack_a, NULL));
			ft_lstadd_back(stack_a, new);
		}
		else
			return (ft_puterror(stack_a, NULL));
		size--;
	}
	return (0);
}

void	ft_getsmall_top(t_list *stack_a)
{
	int		t;
	int		i;
	t_list	*temp;

	temp = stack_a;
	i = 0;
	t = ft_small(stack_a);
	i = ft_findindex(stack_a, t);
	if (i > (ft_lstsize(stack_a) / 2))
		i -= ft_lstsize(stack_a);
	while (i > 0)
	{
		i--;
		ft_rotate(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	while (0 > i)
	{
		i++;
		ft_reverse_rotate(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
}

int	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		size;
	t_list	*t;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (size - i > 3)
	{
		t = (*stack_a)->prev;
		if (ft_push(stack_b, stack_a))
			return (1);
		ft_putstr_fd("pb\n", 1);
		(*stack_a) = t;
		i++;
	}
	ft_sort_3(stack_a);
	if (ft_empty_b(stack_a, stack_b))
		return (1);
	if (ft_small(*stack_a) != ft_lstlast(*stack_a)->content)
		ft_getsmall_top(*stack_a);
	return (0);
}

int	ft_freesplit(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[i])
			free(argv[i++]);
		free(argv);
		return (1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
		return (ft_puterror(&stack_a, NULL));
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (ft_puterror(&stack_a, NULL));
		i = 0;
	}
	if (ft_parse(i, argv, &stack_a))
		return (ft_freesplit(argc, argv));
	if (ft_issorted(stack_a))
	{
		if (ft_sort(&stack_a, &stack_b))
			return (ft_puterror(&stack_a, &stack_b));
	}
	ft_freeall(stack_a, argc, argv);
	return (0);
}
