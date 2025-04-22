/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:31:55 by enorie            #+#    #+#             */
/*   Updated: 2023/12/06 12:31:01 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *stack)
{
	int	t;

	t = stack->content;
	stack->content = stack->prev->content;
	stack->prev->content = t;
}

int	ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*new;

	temp = NULL;
	new = ft_lstnew((*stack_b)->content);
	if (!new)
		return (1);
	if ((*stack_b)->prev)
		temp = (*stack_b)->prev;
	ft_lstadd_back(stack_a, new);
	free(*stack_b);
	(*stack_b) = NULL;
	if (temp)
		(*stack_b) = temp;
	return (0);
}

void	ft_rotate(t_list *stack)
{
	t_list	*t;
	int		nbr;

	t = stack;
	nbr = stack->content;
	while (stack->prev)
	{
		stack->content = stack->prev->content;
		stack = stack->prev;
	}
	stack->content = nbr;
	stack = t;
}

void	ft_reverse_rotate(t_list *stack)
{
	int	nbr;
	int	i;
	int	size;

	i = 1;
	size = ft_lstsize(stack);
	while (stack->prev)
	{
		stack = stack->prev;
	}
	nbr = stack->content;
	while (size > i)
	{
		stack->content = stack->next->content;
		stack = stack->next;
		i++;
	}
	stack->content = nbr;
}
