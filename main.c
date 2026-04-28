/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 02:17:48 by ckurtul           #+#    #+#             */
/*   Updated: 2026/04/28 19:31:31 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stacks;
	char	**split;
	
	split = NULL;
	if (argc == 1)
		return (0);
	stacks = calloc(1, sizeof(t_stack)); // stack e yer ayır malloc ile çünkü bunu yapmazsak  ve = null dersek segf olabilir
	if (!stacks)
		return (1);
	init_counts(stacks); // tüm işlem sayaclarını baslatır
	parse_arg(argv, stacks, split);
	stacks->disorder = disorder(stacks->a);
	give_index(stacks->a);
	if (!stacks->a)			  // (  ./program " "  ) verilirse split null oluyor ve isvalid çağırılmıyor döngüye girmiyor stack bos ise kontrolü
		error(stacks, split); // is order dan önce gerekli yoksa bos liste hatalı davranısa yol açıyor
	if (is_order(stacks->a))  // zaten sıralı mı ?
	{
		cleanup(stacks, split);
		return (0);//double free olmasın diye cleanup da free var
	}
	chunk_base(stacks);
	// strategy_selector(stacks);
	if (stacks->bench)
		bench_press(stacks, stacks->disorder);
	cleanup(stacks, split);
	return (0);
}
