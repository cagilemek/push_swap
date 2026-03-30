/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:56:54 by mucelep           #+#    #+#             */
/*   Updated: 2026/03/31 01:17:57 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	s(stpush **stack)
{
	stpush	*first;
	stpush	*second;

	if (!*stack || !(*stack)->next || !stack)
		return (0);
	first = *stack;
	second = (*stack)->next;
	
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	sa(stpush **a)
{
	if (s(a));
		write(1,"sa\n",3);
}

void	sb(stpush **b)
{
	if (s(b));
		write(1,"sb\n",3);
}
void	ss(stpush **a, stpush **b)
{
	int	check;

	check = 0;
	check += s(a);
	check += s(b);
	if (check)
		write(1,"ss\n",3);
}
