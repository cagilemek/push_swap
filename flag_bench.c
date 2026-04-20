/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bench.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:35:33 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/15 17:22:42 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_press(t_stack *s)
{
	if (!s->bench)
		return ;

	print_line("total: ", s->count.total);
	print_line("sa: ", s->count.sa);
	print_line("sb: ", s->count.sb);
	print_line("ss: ", s->count.ss);
	print_line("pa: ", s->count.pa);
	print_line("pb: ", s->count.pb);
	print_line("ra: ", s->count.ra);
	print_line("rb: ", s->count.rb);
	print_line("rr: ", s->count.rr);
	print_line("rra: ", s->count.rra);
	print_line("rrb: ", s->count.rrb);
	print_line("rrr: ", s->count.rrr);
}

void	print_line(char *name, int value)
{
	write(2, name, ft_strlen(name));
	ft_putnbr_fd(value, 2);
	write(2, "\n", 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_fd(int value, int fd)
{
	char	c;

	if (value >= 10)
		ft_putnbr_fd(value / 10, fd);
	c = (value % 10) + '0';
	write(fd, &c, 1);
}