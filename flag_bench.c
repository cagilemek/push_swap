/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bench.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:35:33 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/28 14:54:51 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_press(t_stack *s, float f)
{
	if (!s->bench)
		return ;
	int		integer;
	int		decimal;

	write(1, "\033[2J\033[3J\033[H", 11);
	disorder_to_integer(&integer, f, &decimal);
	write_disorder(integer, decimal);
	write_total(s->count.total);
	write_sa(s);
	write_ra(s);
	
}

void	putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

void	putnbr_fd(int n, int fd)
{
	char	c;

	if (n >= 10)
		putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void disorder_to_integer(int *integer, float f, int *decimal)
{
	*integer = 100 * f;//float sayının ilk 2 kısmı 49.12 (49)
	*decimal = ((f * 100) - *integer) * 100;//float sayının diger 2 kısmı 49.12 (12)
}
