/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurtul <ckurtul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 02:17:48 by ckurtul           #+#    #+#             */
/*   Updated: 2026/04/02 02:17:59 by ckurtul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	t_stack *stacka;
	t_list *a;
	stacka = malloc(sizeof(t_stack));
	a = malloc(sizeof(t_list));
	a->value = 1;
	
	t_list *b;
	b = malloc(sizeof(t_list));
	b->value = 2;
	a->next = b;
	b->next = NULL;
	t_list *tmp;
	tmp = a;
	while (tmp)
	{
		printf("%d\n",tmp->value);
		tmp = tmp->next;
	}

	stacka->a = a;
	sa(stacka);
	tmp = stacka->a;
	while (tmp)
	{
		printf("%d\n",tmp->value);
		
		tmp = tmp->next;
	}
	printf("\n%d\n",stacka->count.sa);
	
}