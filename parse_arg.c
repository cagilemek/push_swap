/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:57:35 by username          #+#    #+#             */
/*   Updated: 2026/05/12 19:28:36 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_multiple(char **argv, t_stack *stacks, char **split, int i)
{
	int		j;
	long	n;

	split = ft_split(argv[i], ' ');
	j = 0;
	while (split[j])
	{
		if (!is_valid(split[j]))
			error(stacks, split);
		n = ft_atol(split[j]);
		if (n > 2147483647 || n < -2147483648)
			error(stacks, split);
		ft_lstadd_back(&stacks->a, new_node((int) n));
		if (is_duplicate(stacks->a))
			error(stacks, split);
		j++;
	}
	free_split(split);
	split = NULL;
}

void	parse_single(char **argv, t_stack *stacks, char **split, int i)
{
	long	n;

	if (!is_valid(argv[i]))
		error(stacks, split);
	n = ft_atol(argv[i]);
	if (n > 2147483647 || n < -2147483648)
		error(stacks, split);
	ft_lstadd_back(&stacks->a, new_node((int) n));
	if (is_duplicate(stacks->a))
		error(stacks, split);
}

void	parse_arg(char **argv, t_stack *stacks, char **split)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			parse_flag(stacks, argv[i], split);
		else if (ft_strchr(argv[i], ' '))
			parse_multiple(argv, stacks, split, i);
		else
			parse_single(argv, stacks, split, i);
		i++;
	}
}
