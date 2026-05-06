/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurtul <ckurtul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:37:25 by mucelep           #+#    #+#             */
/*   Updated: 2026/05/06 19:34:40 by ckurtul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_base(t_stack *stk)
{
	int	stk_size; // stackin eleman sayısı
	int	chunk_size;// chunk un boyutu = n kök n 
	int	last_chunk; // son chunk ı tutuyor pull chunk için

	stk_size = calculate_stack_size(stk->a);
	chunk_size = calculate_chunk_size(stk_size);
	last_chunk = push_chunk(stk, stk_size, chunk_size);
	pull_chunk(stk, stk_size, chunk_size, last_chunk);
}
//inputları chunklara ayırarak b stackine sıralıyor ama chunklar içinde sayılar sıralı olmuyor
int	push_chunk(t_stack *stk, int stack_size, int chunk_size)
{
	int	chunk;//chunklarınmız
	int	push;// push sayısı cunk a chunksize kadar eleman atsın taşmasın diye

	chunk = 0;
	while (chunk * chunk_size < stack_size)// ör. 0 * 3 < 9 - yeteri kadar chunk olmasını sağlıyor
	{
		push = 0;
		while (push < chunk_size && stk->a)// a biterse yada chunk dolarsa
		{
			if (stk->a->index >= chunk * chunk_size// chunk a giricek index alt tabanı ör 0 * 3 = 0. indexten büyük yada eşitse
				&& stk->a->index < (chunk + 1) * chunk_size)// chunk a giricek index üst tabanı ör (0 + 1) * 3 = 3. indexten küçük 
			{
				pb(stk);//chunk a uyanları b ye at
				push++;
			}
			else
				ra(stk);//chunk a uymuyorsa kaydır
		}
		chunk++;//chunk dolunca 1 arttır
	}
	return (chunk - 1);//en sonda fazladan 1 arttırıp döngüye girmedigi için geçersiz chunk u eksiltiyoruz
}
//chunkların içini sıralayarak geri a ya atıyor en yüksek chunk'ın en yüksek indexinden küçüğe doğru a ya atıyoruz
void	pull_chunk(t_stack *stk, int stack_size, int chunk_size, int last_chunk)
{
	int	max_index;// en yükek index i tutucak
	int	push;

	push = 0;
	max_index = stack_size - 1;
	while (last_chunk >= 0)// en yüksek chunktan geriye dogru gidiyoruz
	{
		push = 0;
		while (push < chunk_size && stk->b)//chunk bittiyse yada stack bittiyse
		{
			if (stk->b->index == max_index)//en yüksek sayıysa a ya at
			{
				pa(stk);
				max_index--;
				push++;
			}
			else//degilse sırayı kaydır
				smart_rotate(stk, max_index);
		}
		last_chunk--;//bir alt chunk
	}
}

int	calculate_stack_size(t_list *stack)//a listesinin kaç elemanlı oldugunu hesaplıyor
{
	int	stack_size;// a listesinin boyutunu tutucak

	stack_size = 0;
	while (stack)
	{
		stack = stack->next;//listenin sonuna kadar gidiyor
		stack_size++;//her seferinde size i 1 arttiriyor
	}
	return (stack_size);
}

int	calculate_chunk_size(int stack_size)//chunk boyutunu hesapla n kök n
{
	int	i;//chunk sayısını tutucak

	i = 1; //çünkü 0 * 0 == 0
	while (i * i < stack_size)// 1*1 < 10? ..... 4*4 < 10?
		i++;
	return (i);
}
