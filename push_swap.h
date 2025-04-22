/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:14:09 by enorie            #+#    #+#             */
/*   Updated: 2024/01/08 15:19:28 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct stack
{
	struct stack	*prev;
	struct stack	*next;
	int				content;
}			t_list;

typedef struct best_action
{
	int	ra;
	int	rb;
}			t_action;

long int	ft_atoi_long(const char *nbr);
int			ft_puterror(t_list **numbers1, t_list **numbers2);
int			ft_check_nbr(char *str);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(int content);
void		ft_swap(t_list *stack);
int			ft_push(t_list **stack_a, t_list **stack_b);
void		ft_rotate(t_list *stack);
void		ft_reverse_rotate(t_list *stack);
int			ft_issorted(t_list *stack);
int			ft_lstsize(t_list *stack);
int			ft_max(t_list *stack);
int			ft_small(t_list *stack);
t_list		*ft_lstfirst(t_list *lst);
int			ft_tabsize(char **argv);
char		**ft_split(char const *s, char c);
void		free_tab(char **tab, size_t k);
int			ft_uniq(t_list *stack, int nbr);
void		ft_sort_3(t_list **stack);
void		ft_freeall(t_list *stack_a, int argc, char **argv);
int			ft_findindex(t_list *stack, int t);
int			ft_empty_b(t_list **stack_a, t_list **stack_b);
int			ft_count_actions(t_list *stack_a, t_list *stack_b);
int			ft_sort(t_list **stack_a, t_list **stack_b);
int			ft_abs(int nbr);
t_action	ft_reverse_rotate_ab(t_list *stack_a, t_list *stack_b, t_action t);
t_action	ft_rotate_ab(t_list *stack_a, t_list *stack_b, t_action t);
t_action	ft_reverse_rotate_a(t_list *stack_a, t_action t);
t_action	ft_reverse_rotate_b(t_list *stack_b, t_action t);
t_action	ft_rotate_a(t_list *stack_a, t_action t);
t_action	ft_rotate_b(t_list *stack_b, t_action t);
int			ft_rb(int rb, int lst);

#endif
