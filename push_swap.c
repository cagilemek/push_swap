/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:56:54 by mucelep           #+#    #+#             */
/*   Updated: 2026/03/31 01:43:40 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	s(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next || !stack)
		return (0);
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	sa(t_list **a)
{
	if (s(a))
		write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	if (s(b))
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	int	check;

	check = 0;
	check += s(a);
	check += s(b);
	if (check)
		write(1, "ss\n", 3);
}

static int	pa(t_list **a, t_list **b, int choice)
{
	t_list	*node;

	node = *b;
	b = (*b)->next;
	node->next = *a;
	*a = node;
	write(1, "pa\n", 3);
}
