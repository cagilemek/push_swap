/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurtul <ckurtul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 00:40:19 by ckurtul           #+#    #+#             */
/*   Updated: 2026/04/02 02:14:42 by ckurtul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  r(t_list **stack)
{
	// t_list *head;
	// head = ilk elemanı tutan pointer
	// *head = value + next
	//  b = head ın adesi 0x100			 = &head
	//  *b = kafa node u gösteren pointer yani = head 
	//  **b = ilk node nin kendisi			  = *head
	t_list *node;

	if (!*stack || !(*stack)->next)
		return (0);
	node = *stack;
	*stack = (*stack)->next;
	node->next = NULL;
	ft_lstadd_back(stack, node);
	return (1);
}

void	ra(t_stack *stk)
{
	if (r(&stk->a))
	{
		write(1, "ra\n", 3);
		stk->count.ra++;
	}
}

void	rb(t_stack *stk)
{
	if (r(&stk->b))
	{
		write(1, "rb\n", 3);
		stk->count.rb++;
	}
}

void	rr(t_stack *stk)
{
	if ((!stk->a || !stk->a->next) || (!stk->b || !stk->b->next))
		return ;
	r(&stk->a);
	r(&stk->b);
	write(1, "rr\n", 3);
	stk->count.rr++;
}