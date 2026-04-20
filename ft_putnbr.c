/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 01:08:21 by mucelep           #+#    #+#             */
/*   Updated: 2026/02/14 01:08:25 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	int	len;
	int	check;

	len = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len += 1;
		n *= -1;
	}
	if (n >= 10)
	{
		check = ft_putnbr(n / 10);
		if (check == -1)
			return (-1);
		len += check;
	}
	check = ft_putchar((n % 10) + '0');
	if (check == -1)
		return (-1);
	len += check;
	return (len);
}
