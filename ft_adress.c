/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 01:00:14 by mucelep           #+#    #+#             */
/*   Updated: 2026/02/14 01:56:55 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_address(void *p)
{
	int	len;
	int	check;

	len = 0;
	if (!p)
	{
		check = ft_putstr("(nil)");
		if (check == -1)
			return (-1);
		len += check;
		return (len);
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	check = ft_hexa((unsigned long)p, "0123456789abcdef");
	if (check == -1)
		return (-1);
	len += check;
	return (len);
}
