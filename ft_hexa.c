/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 01:01:26 by mucelep           #+#    #+#             */
/*   Updated: 2026/02/14 01:08:31 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long nb, char *base)
{
	int	len;
	int	check;

	len = 0;
	if (nb >= 16)
	{
		check = ft_hexa(nb / 16, base);
		if (check == -1)
			return (-1);
		len += check;
	}
	check = ft_putchar((base[nb % 16]));
	if (check == -1)
		return (-1);
	len += check;
	return (len);
}
