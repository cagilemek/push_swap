#include "push_swap.h"

static int get_max_bits(int size)
{
    int max_bits;

    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;
    return (max_bits);
}

void radix_sort(t_stack *stk)
{
    int size;
    int max_bits;
    int i;
    int j;

    size = calculate_stack_size(stk->a);
    give_index(stk->a);
    max_bits = get_max_bits(size);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j++ < size && stk->a)
        {
            if (((stk->a->index >> i) & 1) == 0)
                ra(stk);
            else
                pb(stk);
        }
        while (stk->b)
            pa(stk);
        i++;
    }
}