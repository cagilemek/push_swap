/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 01:02:18 by mucelep           #+#    #+#             */
/*   Updated: 2026/02/14 01:08:14 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unputnbr(unsigned int nb)
{
	int	len;
	int	check;

	len = 0;
	if (nb >= 10)
	{
		check = ft_unputnbr(nb / 10);
		if (check == -1)
			return (-1);
		len += check;
	}
	check = ft_putchar((nb % 10) + '0');
	if (check == -1)
		return (-1);
	len += check;
	return (len);
}
