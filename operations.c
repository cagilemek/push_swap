/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:56:54 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/01 17:10:23 by mucelep          ###   ########.fr       */
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

void	pa(t_list **a, t_list **b)
{
	t_list	*node;

	if (!*b)
		return ;
	node = *b;
	*b = (*b)->next;
	node->next = *a;
	*a = node;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*node;

	if (!*a)
		return ;
	node = *a;
	*a = (*a)->next;
	node->next = *b;
	*b = node;
	write(1, "pb\n", 3);
}

static int	r(t_list **stack)
{
	// t_list *head;

	// head = ilk elemanı tutan pointer
	// *head = value + next

	//  b = head ın adesi 0x100				= &head
	//  *b = kafa node u gösteren pointer yani = head 
	//  **b = ilk node nin kendisi				= *head
	t_list *node;

	if (!*stack || !(*stack)->next)
		return (0);
	node = *stack;
	*stack = (*stack)->next;
	node->next = NULL;
	ft_lstadd_back(stack, node);
	return (1);
}
void	ra(t_list **a)
{
	if (r(a))
		write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	if (r(b))
		write(1, "rb\n", 3);
}
void	rr(t_list **a, t_list **b)
{
	int	check;

	check = 0;
	check += r(a);
	check += r(b);
	if (check)
		write(1, "rr\n", 3);
}

static int	rr_helper(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return (0);
	last = NULL; //gerek yok cunku üstte tek elemanlı olup olmadıgı kontrol ediliyor  sadece güvenlik alıskanlıgı
	tmp = *stack; // orjinal listenin başını tmp de tut
	while (tmp->next)
	{
		last = tmp; // last ta orjinal listenin sondan bir önceki elemanını tut
		tmp = tmp->next; //tmp de orjinal listenin sonunu tut
	}
	(*last).next = NULL; // orjinal listenin son elemanını null yap // liste tek elemanlı olsaydı döngüye girmez ve rastgele bir degerin nextini null yapmaya calısırdı ve segfault o yüzden üstte null var 
	
	tmp->next = *stack; //tmp i yani listenin son elemanını sonu silinmiş liste ile birleştir
	*stack = tmp; // tmp i orjinal listeye at ve liste 3 2 1 olsun
	return (1);
}

void	rra(t_list **a)
{
	if (rr_helper(a))
		write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	if (rr_helper(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	int	check;

	check = 0;
	check += rr_helper(a);
	check += rr_helper(b);
	if (check)
		write(1, "rrr\n", 4);
}