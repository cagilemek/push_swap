/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:55:43 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/20 20:46:14 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_flag(t_stack *stacks, char *argv, char **split)
{
	if (!ft_strcmp(argv, "--simple"))
		stacks->flag = 1;
	else if (!ft_strcmp(argv, "--medium"))
		stacks->flag = 2;
	else if (!ft_strcmp(argv, "--complex"))
		stacks->flag = 3;
	else if (!ft_strcmp(argv, "--adaptive"))
		stacks->flag = 0;
	else if (!ft_strcmp(argv, "--bench"))
	{
		if (stacks->bench)// zaten --bench girilmiş 2. girilmesin diye
			error(stacks, split);
		stacks->bench = 1;
		return ;
	}
	else
		error(stacks, split);
	if (stacks->flagset)
		error (stacks, split);
	stacks->flagset = 1;
}
