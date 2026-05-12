/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 00:41:18 by ckurtul           #+#    #+#             */
/*   Updated: 2026/05/12 20:24:40 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rr_helper(t_list **stack)
{
	t_list	*tmp;
	t_list	*lastonce;

	if (!*stack || !(*stack)->next)
		return (0);
	lastonce = NULL;
	tmp = *stack;
	while (tmp->next)
	{
		lastonce = tmp;
		tmp = tmp->next;
	}
	lastonce->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
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
