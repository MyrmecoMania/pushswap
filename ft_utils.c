/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:20:03 by enorie            #+#    #+#             */
/*   Updated: 2024/01/08 15:22:00 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tabsize(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long int	ft_atoi_long(const char *nbr)
{
	int			i;
	long int	r;
	int			s;

	i = 0;
	r = 0;
	s = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			s *= -1;
		i++;
	}
	while (nbr[i] > 47 && nbr[i] < 58 && r < 2147483648)
	{
		r = r * 10 + (nbr[i] - '0');
		i++;
	}
	if (r == 0)
		return (r);
	return (r * s);
}
