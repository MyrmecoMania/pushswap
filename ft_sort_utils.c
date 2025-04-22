/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:05:45 by enorie            #+#    #+#             */
/*   Updated: 2024/01/06 13:14:04 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_action	ft_rotate_b(t_list *stack_b, t_action t)
{
	ft_rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
	t.rb -= 1;
	return (t);
}

t_action	ft_rotate_a(t_list *stack_a, t_action t)
{
	ft_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
	t.ra -= 1;
	return (t);
}

t_action	ft_reverse_rotate_b(t_list *stack_b, t_action t)
{
	ft_reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
	t.rb += 1;
	return (t);
}

t_action	ft_reverse_rotate_a(t_list *stack_a, t_action t)
{
	ft_reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
	t.ra += 1;
	return (t);
}

t_action	ft_rotate_ab(t_list *stack_a, t_list *stack_b, t_action t)
{
	ft_rotate(stack_b);
	ft_rotate(stack_a);
	t.rb -= 1;
	t.ra -= 1;
	ft_putstr_fd("rr\n", 1);
	return (t);
}
