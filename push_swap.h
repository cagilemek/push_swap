/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:37:07 by mucelep           #+#    #+#             */
/*   Updated: 2026/03/30 23:45:52 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <unistd.h>


typedef struct push_swap
{
	int value;
	struct push_swap *next;
} stpush;

void ss(stpush **a, stpush **b);
void sa(stpush **a);
void sb(stpush **b);

#endif
