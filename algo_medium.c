/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:37:25 by mucelep           #+#    #+#             */
/*   Updated: 2026/05/12 19:54:26 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_base(t_stack *stk)
{
	int	stk_size;
	int	chunk_size;
	int	last_chunk;

	stk_size = calculate_stack_size(stk->a);
	chunk_size = calculate_chunk_size(stk_size);
	last_chunk = push_chunk(stk, stk_size, chunk_size);
	pull_chunk(stk, stk_size, chunk_size, last_chunk);
}

int	push_chunk(t_stack *stk, int stack_size, int chunk_size)
{
	int	witch_chunk;
	int	push;

	witch_chunk = 0;
	while (witch_chunk * chunk_size < stack_size)
	{
		push = 0;
		while (push < chunk_size && stk->a)
		{
			if (stk->a->index >= witch_chunk * chunk_size
				&& stk->a->index < (witch_chunk + 1) * chunk_size)
			{
				pb(stk);
				push++;
			}
			else
				ra(stk);
		}
		witch_chunk++;
	}
	return (witch_chunk - 1);
}

void	pull_chunk(t_stack *stk, int stack_size, int chunk_size, int last_chunk)
{
	int	max_index;
	int	push;

	push = 0;
	max_index = stack_size - 1;
	while (last_chunk >= 0)
	{
		push = 0;
		while (push < chunk_size && stk->b)
		{
			if (stk->b->index == max_index)
			{
				pa(stk);
				max_index--;
				push++;
			}
			else
				smart_rotate(stk, max_index);
		}
		last_chunk--;
	}
}

int	calculate_stack_size(t_list *stack)
{
	int	stack_size;

	stack_size = 0;
	while (stack)
	{
		stack = stack->next;
		stack_size++;
	}
	return (stack_size);
}

int	calculate_chunk_size(int stack_size)
{
	int	i;

	i = 1;
	while (i * i < stack_size)
		i++;
	return (i);
}
