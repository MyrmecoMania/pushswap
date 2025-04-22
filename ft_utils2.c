/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:10:07 by root              #+#    #+#             */
/*   Updated: 2023/12/06 12:54:53 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_list *stack)
{
	int	t;

	t = stack->content;
	while (stack)
	{
		if (stack->content > t)
			t = stack->content;
		stack = stack->prev;
	}
	return (t);
}

int	ft_small(t_list *stack)
{
	int	t;

	t = stack->content;
	while (stack)
	{
		if (stack->content < t)
			t = stack->content;
		stack = stack->prev;
	}
	return (t);
}

int	ft_findindex(t_list	*stack, int t)
{
	int	i;

	i = 0;
	while (stack->content != t)
	{
		i++;
		stack = stack->prev;
	}
	return (i);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr *= -1);
	return (nbr);
}
