/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:33:15 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/28 15:33:55 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)//listenin ilk elemanı ile kalan tüm elemanları kaysılastır
		{
			if (lst->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;//listenin 2. elemanına geç
	}
	return (0);
}

void	give_index(t_list *a)
{
	t_list	*current;
	t_list	*runner;
	int		index;

	current = a;
	while (current)
	{
		index = 0;
		runner = a;
		while (runner)
		{
			if (runner->value < current->value)
				index++;
			runner = runner->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	is_order(t_list *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	cleanup(t_stack *stacks, char **split)
{
	free_split(split);
	free_list(stacks->a);
	free_list(stacks->b);
	free(stacks);
	return (0);
}