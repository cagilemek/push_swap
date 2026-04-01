/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurtul <ckurtul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 00:39:12 by ckurtul           #+#    #+#             */
/*   Updated: 2026/04/02 02:15:03 by ckurtul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stk)
{
	t_list	*node;

	if (!stk->b)
		return ;
	node = stk->b;
	stk->b = stk->b->next;
	node->next = stk->a;
	stk->a = node;
	write(1, "pa\n", 3);
	stk->count.pa++;
}

void	pb(t_stack *stk)
{
	t_list	*node;

	if (!stk->a)
		return ;
	node = stk->a;
	stk->a = stk->a->next;
	node->next = stk->b;
	stk->b = node;
	write(1, "pb\n", 3);
	stk->count.pb++;
}