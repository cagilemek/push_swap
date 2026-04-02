/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurtul <ckurtul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 00:41:18 by ckurtul           #+#    #+#             */
/*   Updated: 2026/04/02 03:47:45 by ckurtul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int  rr_helper(t_list **stack)
{
	t_list  *tmp;
	t_list  *last;

	if (!*stack || !(*stack)->next)
		return (0);
	last = NULL; //gerek yok cunku üstte tek elemanlı olup olmadıgı kontrol ediliyor  sadece güvenlik alıskanlıgı
	tmp = *stack; // orjinal listenin başını tmp de tut
	while (tmp->next)
	{
		last = tmp; // last ta orjinal listenin sondan bir önceki elemanını tut
		tmp = tmp->next; //tmp de orjinal listenin sonunu tut
	}
	(*last).next = NULL; // orjinal listenin son elemanını null yap // liste tek elemanlı olsaydı döngüye girmez ve rastgele bir degerin nextini null yapmaya calısırdı ve segfault o yüzden üstte null var 
	tmp->next = *stack; //tmp i yani listenin son elemanını sonu silinmiş liste ile birleştir
	*stack = tmp; // tmp i orjinal listeye at ve liste 3 2 1 olsun
	return (1);
}

void	rra(t_stack *stk)
{
	if (rr_helper(&stk->a))
	{
		write(1, "rra\n", 4);
		stk->count.rra++;
		stk->count.total++;
	}
}
void	rrb(t_stack *stk)
{
	if (rr_helper(&stk->b))
	{
		write(1, "rrb\n", 4);
		stk->count.rrb++;
		stk->count.total++;
	}
}

void	rrr(t_stack *stk)
{
	if ((!stk->a || !stk->a->next) || (!stk->b || !stk->b->next))
		return ;
	rr_helper(&stk->a);
	rr_helper(&stk->b);
	write(1, "rrr\n", 4);
	stk->count.rrr++;
	stk->count.total++;
}