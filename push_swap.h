/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:37:07 by mucelep           #+#    #+#             */
/*   Updated: 2026/03/31 01:44:01 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>

typedef struct s_list
{
	int					value;
	struct push_swap	*next;
}	t_list;

void	ss(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);

#endif
