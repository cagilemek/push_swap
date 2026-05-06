/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_find_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 05:28:15 by mucelep           #+#    #+#             */
/*   Updated: 2026/05/05 06:32:55 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//listedeki en yüksek indexin nerede oldugunu buluyor
int	find_max_index_pos(t_list *b, int max_index)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b->index == max_index)// max index i arıyor
			return (i);//buldugunda kaçıncı sırada oldugunu return ediyor
		i++;
		b = b->next;
	}
	return (i);//güvenlik için var
}
void	fin_min_index_pos(t_list *a, int *min_index, int *min_pos)
{
	t_list	*current = a;
	int		i;

	i = 0;

	if (!current)
		return;

	*min_index = current->index;
	*min_pos = 0; // min_pos stack a içindeki en küçük index in pozisyonunu tutar
	
	while (current)
	{
		if (current->index < *min_index)
		{
			*min_index = current->index;
			*min_pos = i;
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
	if (pos == size)  // bulunamadı
		return ;
	if (pos <= size / 2)
		rb(stk);
	else
		rrb(stk);
}