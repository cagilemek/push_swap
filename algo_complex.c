/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algo_complex.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/07 02:48:50 by username         #+#    #+#              */
/*   Updated: 2026/05/07 02:48:50 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *stk)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = calculate_stack_size(stk->a);
	give_index(stk->a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stk->a->index >> i) & 1) == 0)
				pb(stk);
			else
				ra(stk);
			j++;
		}
		while (stk->b)
			pa(stk);
		i++;
	}
}
