/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:04:10 by enorie            #+#    #+#             */
/*   Updated: 2023/12/06 13:55:21 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_puterror(t_list **numbers1, t_list **numbers2)
{
	t_list	*t;

	while (numbers1 && *numbers1)
	{
		t = (*numbers1)->prev;
		free(*numbers1);
		(*numbers1) = t;
	}
	while (numbers2 && *numbers2)
	{
		t = (*numbers2)->prev;
		free(*numbers2);
		(*numbers2) = t;
	}
	ft_putstr_fd("Error", 2);
	return (1);
}

int	ft_check_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (!str[i] || (str[i] != '+' && str[i] != '-'
			&& !(str[i] >= 48 && str[i] <= 57)))
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < 48 || str[i] > 57)
		return (1);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i])
		return (1);
	return (0);
}

int	ft_issorted(t_list *stack)
{
	int	i;
	int	r;

	r = 1;
	i = stack->content;
	while (stack->prev)
	{
		if (i > stack->prev->content)
			return (r);
		stack = stack->prev;
		if (stack)
			i = stack->content;
		r++;
	}
	return (0);
}

int	ft_uniq(t_list *stack, int nbr)
{
	while (stack)
	{
		if (stack->content == nbr)
			return (1);
		stack = stack->prev;
	}
	return (0);
}

void	ft_freeall(t_list *stack_a, int argc, char **argv)
{
	t_list	*temp;

	temp = stack_a;
	if (argc == 2)
		free_tab(argv, ft_tabsize(argv));
	while (stack_a)
	{
		temp = stack_a->prev;
		free(stack_a);
		stack_a = temp;
	}
}
