/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckurtul <ckurtul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 18:19:00 by ckurtul           #+#    #+#             */
/*   Updated: 2026/04/02 19:41:02 by ckurtul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float disorder (int *atol, int size)
{
	float	mistakes;
	float total_pairs;
	int i;
	int j;
	
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	j = 0;
	
	if(size <= 1)
		return(0);
	while(i < size -1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if(atol[i] > atol[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return(mistakes/total_pairs);
}

void strategy_selector (int *arr, int size)
{
	float d;
	
	d = disorder(arr, size);

	if (d == 0)
		return;
	else if (d < 0.2)
		simple_sort(arr, size);
	else if (d >= 0.2 && d <= 0.5)
		medium_sort(arr, size);
	else
		complex_sort(arr, size);

}