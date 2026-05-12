/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_find_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 05:28:15 by mucelep           #+#    #+#             */
/*   Updated: 2026/05/12 20:16:01 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index_pos(t_list *b, int max_index)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b->index == max_index)
			return (i);
		i++;
		b = b->next;
	}
	return (i);
}

void	fin_min_index_pos(t_list *a, int *min_index, int *min_pos_index)
{
	t_list	*current;
	int		i;

	i = 0;
	current = a;
	if (!current)
		return ;
	*min_index = current->index;
	*min_pos_index = 0;
	while (current)
	{
		if (current->index < *min_index)
		{
			*min_index = current->index;
			*min_pos_index = i;
		}
		current = current->next;
		i++;
	}
}

void	smart_rotate(t_stack *stk, int max_index)
{
	int	pos;
	int	size;

	size = calculate_stack_size(stk->b);
	if (size == 0)
		return ;
	pos = find_max_index_pos(stk->b, max_index);
	if (pos <= size / 2)
		rb(stk);
	else
		rrb(stk);
}
