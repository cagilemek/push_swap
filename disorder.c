/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:19:00 by username          #+#    #+#             */
/*   Updated: 2026/05/12 19:25:58 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder(t_list *head)
{
	float	mistakes;
	float	total_pairs;
	t_list	*current;
	t_list	*runner;

	current = head;
	mistakes = 0;
	total_pairs = 0;
	if (!current)
		return (0);
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			total_pairs += 1;
			if (current->value > runner->value)
				mistakes += 1;
			runner = runner->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}

void	strategy_selector(t_stack *stacks)
{
	int	size;

	size = calculate_stack_size(stacks->a);
	if (size <= 5 && stacks->flag == 0)
		sort_mini(stacks);
	else if (stacks->flag == 1)
		simple(stacks);
	else if (stacks->flag == 2)
		chunk_base(stacks);
	else if (stacks->flag == 3)
		radix_sort(stacks);
	else
	{
		if (stacks->disorder < 0.2)
			simple(stacks);
		else if (stacks->disorder < 0.5)
			chunk_base(stacks);
		else
			radix_sort(stacks);
	}
}
