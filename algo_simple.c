
#include "push_swap.h"

void move_to_top(t_stack *stk, int pos)
{
	int size;

	if (pos < 0)
		return;
	size = calculate_stack_size(stk->a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stk);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rra(stk);
			pos--;
		}
	}
}

void simple(t_stack *stk)
{
	int min_index;
	int min_pos;

	while (stk->a)
	{
		give_index(stk->a);
		fin_min_index_pos(stk->a, &min_index, &min_pos);
		move_to_top(stk, min_pos);
		pb(stk);
	}
	while (stk->b)
		pa(stk);
}
