/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:37:25 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/14 02:04:26 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_base(t_stack *stk)
{
	
}

int	calculate_stack_size(t_list *stack)//a listesinin kaç elemanlı oldugunu hesaplıyor
{
	int	stack_size;// a listesinin boyutunu tutucak

	stack_size = 0;
	while (stack)
	{
		stack = stack->next;//listenin sonuna kadar gidiyor
		stack_size++;//her seferinde size i 1 arttiriyor
	}
	return (stack_size);
}

int	calculate_chunk_size(int stack_size)//chunk boyutunu hesapla n kök n
{
	int	i;//chunk sayısını tutucak

	i = 1; //0 * 0 == 0
	while (i * i < stack_size)// 1*1 < 10? ..... 4*4 < 10?
		i++;
	return (i);
}
