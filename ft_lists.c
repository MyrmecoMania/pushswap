/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:02:58 by enorie            #+#    #+#             */
/*   Updated: 2023/12/04 14:30:16 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t;

	if (!lst)
		return (NULL);
	t = lst;
	while (t->next)
		t = t->next;
	return (t);
}

t_list	*ft_lstfirst(t_list *lst)
{
	t_list	*t;

	if (!lst)
		return (NULL);
	t = lst;
	while (t->prev)
		t = t->prev;
	return (t);
}

t_list	*ft_lstnew(int content)
{
	t_list	*r;

	r = malloc(sizeof(t_list));
	if (!r)
		return (NULL);
	r->content = content;
	r->next = NULL;
	r->prev = NULL;
	return (r);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (lst)
	{
		if (*lst)
		{
			(*lst)->next = new;
			new->prev = (*lst);
			(*lst) = new;
		}
		else
			(*lst) = new;
	}
}

int	ft_lstsize(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->prev;
	}
	return (i);
}
