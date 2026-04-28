/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:57:35 by mucelep           #+#    #+#             */
/*   Updated: 2026/04/28 19:23:54 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_multiple(char **argv, t_stack *stacks, char **split, int i)
{
	int j;	// split ettigimiz "1 2 3" gibi tırnak içindeki 1 2 3 arasında gezebilmek için
	long n; // normal ve split ile aldıgmız argümanı atol ile integer olarak n de tutuyoruz

	split = ft_split(argv[i], ' '); // split == &split[0] || *split == split[0] || **split == split[0][0]
	j = 0;
	while (split[j])
	{
		if (!is_valid(split[j]))
			error(stacks, split);
		n = ft_atol(split[j]);
		if (n > 2147483647 || n < -2147483648)
			error(stacks, split);
		ft_lstadd_back(&stacks->a, new_node((int)n));
		if (is_duplicate(stacks->a)) // aynı sayı tekrarı kontrolü
			error(stacks, split);
		j++;
	}
	free_split(split);
	split = NULL;
}

void	parse_single(char **argv, t_stack *stacks, char **split, int i)
{
	long	n; // normal ve split ile aldıgmız argümanı atol ile integer olarak n de tutuyoruz

	if (!is_valid(argv[i])) // sayı mı kontrolü
		error(stacks, split);
	n = ft_atol(argv[i]);
	if (n > 2147483647 || n < -2147483648)
		error(stacks, split);
	ft_lstadd_back(&stacks->a, new_node((int)n));
	if (is_duplicate(stacks->a)) // aynı sayı tekrarı kontolü
		error(stacks, split);
}

void	parse_arg(char **argv, t_stack *stacks, char **split)
{
	
	int i;	// argümanları gezmek için

	i = 1;
	while (argv[i])		 // bütün argümanları gez PARSİNG
	{
		if (argv[i][0] == '-' && argv[i][1] == '-') // flag kontrolü
			parse_flag(stacks, argv[i], split);
		else if (ft_strchr(argv[i], ' ')) // 1. argümanda bosluk var mı diye kontrol et yani "" içinde mi
			parse_multiple(argv, stacks, split, i);
		else // argüman tırnak içinde degilse
			parse_single(argv, stacks, split, i);
		i++;
	}
}
