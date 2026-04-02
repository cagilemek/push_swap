/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 00:38:37 by ckurtul           #+#    #+#             */
/*   Updated: 2026/04/02 05:07:30 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	s(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	sa(t_stack *stk)
{
	if (s(&stk->a))
	{
		write(1, "sa\n", 3);
		stk->count.sa++;
		stk->count.total++;
	}
}

void	sb(t_stack *stk)
{
	if (s(&stk->b))
{
		write(1, "sb\n", 3);
		stk->count.sb++;
		stk->count.total++;
	}
}

void	ss(t_stack *stk)
{
	if ((!stk->a || !stk->a->next) || (!stk->b || !stk->b->next))
		return ;
	s(&stk->a);
	s(&stk->b);
	write(1, "ss\n", 3);
	stk->count.ss++;//BURAYI TARTIŞIN BENCE DOĞRU -Ç
	stk->count.total++;
}
