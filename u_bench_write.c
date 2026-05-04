/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_bench_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:33:50 by mucelep           #+#    #+#             */
/*   Updated: 2026/05/05 00:55:15 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_disorder(int integer, int decimal)
{
	putstr_fd("[bench] disorder: ", 2);
	putnbr_fd(integer,2);
	putstr_fd(".",2);
	putnbr_fd(decimal,2);
	putstr_fd("%\n",2);
}

void	write_total(int total)
{
	putstr_fd("[bench] total_ops: ", 2);
	putnbr_fd(total, 2);
	putstr_fd("\n",2);
}

// void	write_strategy()
// {
	
// }

void	write_sa(t_stack *a)
{
	putstr_fd("[bench] sa: ", 2);
	putnbr_fd(a->count.sa, 2);
	putstr_fd("	sb: ", 2);
	putnbr_fd(a->count.sb, 2);
	putstr_fd("	ss: ", 2);
	putnbr_fd(a->count.ss, 2);
	putstr_fd("	pa: ", 2);
	putnbr_fd(a->count.pa, 2);
	putstr_fd("	pb: ", 2);
	putnbr_fd(a->count.pb, 2);
	putstr_fd("\n",2);
}

void	write_ra(t_stack *a)
{
	putstr_fd("[bench] ra: ", 2);
	putnbr_fd(a->count.ra, 2);
	putstr_fd("	rb: ", 2);
	putnbr_fd(a->count.rb, 2);
	putstr_fd("	rr: ", 2);
	putnbr_fd(a->count.rr, 2);
	putstr_fd("	rra: ", 2);
	putnbr_fd(a->count.rra, 2);
	putstr_fd("	rrb: ", 2);
	putnbr_fd(a->count.rrb, 2);
	putstr_fd("	rrr: ", 2);
	putnbr_fd(a->count.rrr, 2);
	putstr_fd("\n",2);
}
