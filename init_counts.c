/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_counts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 04:22:39 by ckurtul           #+#    #+#             */
/*   Updated: 2026/04/02 05:04:32 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_counts(t_stack *stk)
{
	stk->count.sa = 0;
	stk->count.sb = 0;
	stk->count.ss = 0;
	stk->count.pa = 0;
	stk->count.pb = 0;
	stk->count.ra = 0;
	stk->count.rb = 0;
	stk->count.rr = 0;
	stk->count.rra = 0;
	stk->count.rrb = 0;
	stk->count.rrr = 0;
	stk->count.total = 0;
}