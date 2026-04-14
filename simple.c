/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 03:22:39 by ckurtul           #+#    #+#             */
/*   Updated: 2026/04/14 04:49:00 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple(t_stack *stk)
{
	int	min_index;
	int	min_pos;

	give_index(stk->a);//head i değiştirimiyor sadece mevcut node un içini değiştiriyor o yüzden tek pointer

	while (stk->a)
	{
		fin_min_index_pos(stk->a, &min_index, &min_pos);
		move_to_top(&stk->a, min_pos);//stk bir pointer ve onun adresini alırsak pointer to pointer oluyor aslında bu nedenle & kullanıyoruz çünkü orjinalde değişiklik yapmak isterotti ve bu fonksiyon bulduğumuz minimum değerimizi head stacke atar
		pb(stk);
	}

	while (stk->b)
		pa(stk);
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

void	move_to_top();
