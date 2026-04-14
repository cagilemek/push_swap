/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 02:17:48 by ckurtul           #+#    #+#             */
/*   Updated: 2026/04/14 05:50:30 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stacks;
	char	**split;
	long	n;//split ile aldıgmız argümanı atol ile n de tutuyoruz
	int		j;//split ettigimiz "1 2 3" gibi tırnak içindeki 1 2 3 arasında gezebilmek için
	int		i;//argümanları gezmek için

	if (argc == 1)
		return (0);
	stacks = malloc(sizeof(t_stack));// stack e yer ayır malloc ile 
	if (!stacks)
		return (1);
	stacks->a = NULL;// baslangıç degeri ver garbage olmasın diye
	stacks->b = NULL;
	split = NULL;
	i = 1;
	init_counts(stacks);// tüm işlem sayaclarını baslatır
	while (i < argc)// bütün argümanları gez PARSİNG
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')// flag kontrolü
			parse_flag(stacks, argv[i], split);
		else if (ft_strchr(argv[i], ' ')) // 1. argümanda bosluk var mı diye kontrol et yani "" içinde mi
		{
			split = ft_split(argv[i], ' ');// split == &split[0] || *split == split[0] || **split == split[0][0]
			j = 0;
			while (split[j])
			{
				if (!is_valid(split[j]))
					error(stacks, split);
				n = ft_atol(split[j]);
				if (n > 2147483647 || n < -2147483648)
					error(stacks, split);
				ft_lstadd_back(&stacks->a, new_node((int)n));
				if (is_duplicate(stacks->a))//aynı sayı tekrarı kontrolü
					error (stacks, split);
				j++;
			}
			free_split(split);// iki tane "1 2" 9 "3 4" split gerekirse diye ilk splitte leak olmaması içn
			split = NULL;// burda istemiyorsan free split fonksiyonu *** olacak ve (&split) göndereceksin
		}
		else // argüman tırnak içinde degilse
		{
			if (!is_valid(argv[i])) // sayı mı kontrolü
				error(stacks, split);
			n = ft_atol(argv[i]);
			if (n > 2147483647 || n < -2147483648)
				error(stacks, split);
			ft_lstadd_back(&stacks->a, new_node((int)n));
			if (is_duplicate(stacks->a))// aynı sayı tekrarı kontolü
				error (stacks, split);
		}
		i++;
	}
	give_index(stacks->a);
	if (!stacks->a)// (  ./program " "  ) verilirse split null oluyor ve isvalid çağırılmıyor döngüye girmiyor stack bos ise kontrolü
		error(stacks, split);// is order dan önce gerekli yoksa bos liste hatalı davranısa yol açıyor
	if (is_order(stacks->a))// zaten sıralı mı ?
	{
		cleanup(stacks, split);
		return (0);
	}
	strategy_selector(stacks);
	cleanup(stacks, split);
	return (0);
}
