/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:19:00 by ckurtul           #+#    #+#             */
/*   Updated: 2026/04/21 14:24:41 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float disorder(t_list *head)
{
	float mistakes;
	float total_pairs;
	t_list *current; // stacki tutuyo
	t_list *runner;	 // bir sonraki stacki tutuyor
	current = head;
	mistakes = 0;
	total_pairs = 0;

	if (!current)
		return (0);
	while (current)
	{
		runner = current->next; // bağlıyoruz birbirine
		while (runner)
		{
			total_pairs += 1;
			if (current->value > runner->value) // değer kontrolü yapıyoruz elemanlar birbirinden büyük mü
				mistakes += 1;
			runner = runner->next;
		}
		current = current->next; // teker teker tüm elemanlar ile kıyas
	}
	return (mistakes / total_pairs); // burda oranı buluyoruz önce küçük sayı oldugu için 1 den düşük cıkıyor ör 1/2 = 0.5
}

// void strategy_selector(t_stack *stacks)
// {
// 	float rate;

// 	rate = disorder(stacks->a); // SADECE A YA BAKIYORUZ ANLAMADIM KAFAM ÇOK KARIŞTI B YE DE BAKMAMIZ GEREKMEZ Mİ BİLMİYORUM İMDAT
// 	if (rate < 0.2)
// 		simple(stacks);
// 	else if (rate < 0.5)
// 		chunk_base(stacks);
// 	else
// 		sort_large(stacks);
// }
