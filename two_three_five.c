/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   two_three_five.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/06 18:37:57 by username         #+#    #+#              */
/*   Updated: 2026/05/07 02:49:27 by username        ###   ########.fr        */
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
	if (one > two && two < three && one < three) // [1, 0, 2] → sa
		sa(s);
	else if (one > two && two > three)
	{
		sa(s);
		rra(s);
	}
	else if (one > two && two < three && one > three) // [2, 0, 1] → rra
		ra(s);
	else if (one < two && two > three && one < three) // [0, 2, 1] → ra + sa
	{
		rra(s);
		sa(s);
	}
	else if (one < two && two > three && one > three) // [1, 2, 0] → rra + sa
		rra(s);
	return ;
}

void	sort_mini(t_stack *s)
{
	int	i;
	int	size;

	i = 0;
	size = calculate_stack_size(s->a);
	if (size <= 2)
		two(s);
	else if (size <= 3)
		three(s);
	else if (size > 3 && size < 6)
	{
		while (i < 2)
		{
			give_index(s->a);
			min_push_b(s);
			i++;
		}
		size = calculate_stack_size(s->a);
		// kaç eleman kaldı?
		if (size == 2)
			two(s);
		else if (size == 3)
			three(s);
		while (i > 0)
		{
			pa(s);
			i--;
		}
	}
	return ;
}

void	min_push_b(t_stack *s)
{
	while (s->a->index != 0)
		ra(s);
	pb(s);
	return ;
}
