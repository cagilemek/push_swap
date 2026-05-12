/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 02:17:48 by username          #+#    #+#             */
/*   Updated: 2026/05/12 19:26:23 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	char	**split;

	split = NULL;
	if (argc == 1)
		return (0);
	stacks = calloc(1, sizeof(t_stack));
	if (!stacks)
		return (1);
	init_counts(stacks);
	parse_arg(argv, stacks, split);
	stacks->disorder = disorder(stacks->a);
	give_index(stacks->a);
	if (!stacks->a)
		error(stacks, split);
	if (is_order(stacks->a))
	{
		cleanup(stacks, split);
		return (0);
	}
	strategy_selector(stacks);
	if (stacks->bench)
		bench_press(stacks, stacks->disorder);
	cleanup(stacks, split);
	return (0);
}
