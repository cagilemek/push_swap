/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bench.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:35:33 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/20 23:46:09 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_press(t_stack *s, float f)
{
	if (!s->bench)
		return ;
	int		integer;
	float	flo;
	int		decimal;

	disorder_to_integer(&integer, &flo, &decimal, f);
	
	ft_printf("[bench] disorder: %d.%d%%\n",integer, decimal);
	ft_printf("[bench] total_ops: %d\n",s->count.total);
	ft_printf("[bench] strategy:\n");
	ft_printf("[bench] sa: %d sb: %d ss: %d\n", s->count.sa, s->count.sb, s->count.ss);
	ft_printf("[bench] pa: %d pb: %d\n", s->count.pa, s->count.pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d\n", s->count.ra, s->count.rb, s->count.rr);
	ft_printf("[bench] rra: %d rrb: %d rrr: %d\n", s->count.rra, s->count.rrb, s->count.rrr);
	

}

void disorder_to_integer(int *integer, float *flo, int *decimal, float f)
{
	*integer = 100 * f;//float sayının ilk 2 kısmı 49.12 (49)
	*flo = 100 * f;//flo tüm sayıyı tutuyor 49.12
	*decimal = (*flo - *integer) * 100;//float sayının diger 2 kısmı 49.12 (12)
}