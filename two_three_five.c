/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_three_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:37:57 by username          #+#    #+#             */
/*   Updated: 2026/05/12 20:50:18 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two(t_stack *s)
{
	int	one;
	int	two;

	one = s->a->index;
	two = s->a->next->index;
	if (one > two)
		sa(s);
	return ;
}

void	three(t_stack *s)
{
	int	one;
	int	two;
	int	three;

	one = s->a->index;
	two = s->a->next->index;
	three = s->a->next->next->index;
	if (one > two && two < three && one < three)
		sa(s);
	else if (one > two && two > three)
	{
		sa(s);
		rra(s);
	}
	else if (one > two && two < three && one > three)
		ra(s);
	else if (one < two && two > three && one < three)
	{
		rra(s);
		sa(s);
	}
	else if (one < two && two > three && one > three)
		rra(s);
	return ;
}

void	min_push_b(t_stack *s)
{
	while (s->a->index != 0)
		ra(s);
	pb(s);
	return ;
}

static void	sort_small(t_stack *s)
{
	int	size;

	size = calculate_stack_size(s->a);
	if (size == 2)
		two(s);
	else if (size == 3)
		three(s);
}

void	sort_mini(t_stack *s)
{
	int	i;
	int	size;

	size = calculate_stack_size(s->a);
	if (size <= 3)
		return (sort_small(s));
	i = 0;
	while (i < 2)
	{
		give_index(s->a);
		min_push_b(s);
		i++;
	}
	sort_small(s);
	while (i--)
		pa(s);
}
