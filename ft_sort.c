/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:11:56 by root              #+#    #+#             */
/*   Updated: 2024/01/06 13:15:56 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_action	ft_reverse_rotate_ab(t_list *stack_a, t_list *stack_b, t_action t)
{
	ft_reverse_rotate(stack_b);
	ft_reverse_rotate(stack_a);
	t.rb += 1;
	t.ra += 1;
	ft_putstr_fd("rrr\n", 1);
	return (t);
}

void	ft_sort_3(t_list **stack)
{
	int	max;

	if (!ft_issorted(*stack))
		return ;
	max = ft_max(*stack);
	if ((*stack)->content == max)
	{
		ft_rotate(*stack);
		ft_putstr_fd("ra\n", 1);
	}
	else if ((*stack)->prev->content == max)
	{
		ft_reverse_rotate(*stack);
		ft_putstr_fd("rra\n", 1);
	}
	if ((*stack)->content > (*stack)->prev->content)
	{
		ft_swap(*stack);
		ft_putstr_fd("sa\n", 1);
	}
}

int	ft_count_actions(t_list *stack_a, t_list *stack_b)
{
	int		t;
	int		i;
	t_list	*temp;

	t = ft_max(stack_a);
	temp = stack_a;
	i = 0;
	if (stack_b->content >= ft_max(stack_a))
		t = ft_small(stack_a);
	else
	{
		while (stack_a)
		{
			if (stack_a->content >= stack_b->content && t > stack_a->content)
				t = stack_a->content;
			stack_a = stack_a->prev;
		}
	}
	stack_a = temp;
	i = ft_findindex(stack_a, t);
	if (i > (ft_lstsize(stack_a) / 2))
		i -= ft_lstsize(stack_a);
	return (i);
}

t_action	ft_find_best(t_list *stack_a, t_list *stack_b)
{
	t_action	r;
	int			t_rb;
	int			t_ra;
	int			size;

	size = ft_lstsize(stack_b);
	t_rb = 0;
	r.ra = ft_count_actions(stack_a, stack_b);
	r.rb = t_rb;
	while (stack_b)
	{
		t_ra = ft_count_actions(stack_a, stack_b);
		if (ft_abs(t_ra) + ft_abs(ft_rb(t_rb, size))
			< ft_abs(r.ra) + ft_abs(r.rb))
		{
			r.ra = t_ra;
			r.rb = ft_rb(t_rb, size);
		}
		t_rb++;
		stack_b = stack_b->prev;
	}
	if (r.rb > (ft_lstsize(stack_b) / 2))
		r.rb -= ft_lstsize(stack_b);
	return (r);
}

int	ft_empty_b(t_list **stack_a, t_list **stack_b)
{
	int			i;
	t_action	t;

	i = 0;
	while (*stack_b)
	{
		t = ft_find_best(*stack_a, *stack_b);
		while (t.ra > 0 && t.rb > 0)
			t = ft_rotate_ab(*stack_a, *stack_b, t);
		while (t.ra < 0 && t.rb < 0)
			t = ft_reverse_rotate_ab(*stack_a, *stack_b, t);
		while (t.ra > 0)
			t = ft_rotate_a(*stack_a, t);
		while (t.rb > 0)
			t = ft_rotate_b(*stack_b, t);
		while (t.ra < 0)
			t = ft_reverse_rotate_a(*stack_a, t);
		while (t.rb < 0)
			t = ft_reverse_rotate_b(*stack_b, t);
		if (ft_push(stack_a, stack_b))
			return (1);
		ft_putstr_fd("pa\n", 1);
	}
	return (0);
}
